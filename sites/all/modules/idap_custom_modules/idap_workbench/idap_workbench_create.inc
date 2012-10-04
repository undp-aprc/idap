<?php

/* Page callback for admin/structure/workbench/add */
function idap_workbench_add() {
	$form = drupal_get_form('idap_workbench_form_theme_section');
	return $form;
}

/* Form array for 'idap_workbench_form_theme_section' */
function idap_workbench_form_theme_section($form, &$form_state) {
	$form['sid'] = array(
		'#type' => 'hidden',
		//'#value' => $sid,
	);
	$form['title'] = array(
		'#type' => 'textfield',
		'#title' => t('Section Title'),
		'#required' => TRUE,
		//'#default_value' => $title,
	);
	$form['machine_name'] = array(
		'#type' => 'machine_name',
		'#machine_name' => array(
			'source' => array('title'),
			'label' => t('Machine Name'),
			'exists' => 'section_name_exists'
		),
	);
	$form['section'] = array(
		'#type' => 'fieldset',
		'#title' => t('Thematic Section Properties'),
		'#description' => t('Please choose the pillar to which this section belongs. This sets where the section appears in the site\'s main naviagation structure.'),
	);
	$form['section']['taxonomy_parent'] = array(
		'#type' => 'radios',
		'#options' => idap_workbench_load_taxonomy_vocab(),
		'#required' => TRUE,
		//'#default_value' => $taxonomy_parent,
	);
	$form['section']['banner_image'] = array(
		'#title' => t('Banner Image'),
		 '#type' => 'managed_file',
		 '#description' => t('This image must be 983 pixels wide by 150 pixels high.'),
		 '#default_value' => variable_get('carousel_image'),
		 '#upload_location' => 'public://thematic_sections/banner_images/',
	);
	$form['carousel'] = array( // @to do: add size and filetype validation and create in form preview image
		'#type' => 'fieldset',
		'#title' => t('carousel'),
		'#description' => t('These options are used to create an item that appears on the home page carousel. <em>Note:</em> The title for the carousel item will be taken from the title field above.'),
		'#tree' => TRUE,
	);
	$form['carousel']['body'] = array(
		'#type' => 'textarea',
		'#title' => t('Carousel Text'),
		'#description' => t('The text in this box will be displayed on the carousel item. We recommend this text be less than 50 words.'),
		'#required' => TRUE,
	);
	$form['carousel']['carousel_image'] = array( // @to do: add size and filetype validation and create in form preview image
		'#title' => t('Carousel Image'),
		 '#type' => 'managed_file',
		 '#description' => t('This image should be 380 pixels wide by 250 pixels high.'),
		 '#default_value' => variable_get('carousel_image',''),
		 '#upload_location' => 'public://thematic_sections/carousel_images/',
	);	
	$form['submit'] = array(
	    '#type' => 'submit', 
	    '#value' => t('Create Section'),
	  );

	$form['#submit'][] = 'idap_workbench_form_theme_section_submit_new';
	$form['#redirect'] = 'admin/structure/workbench';	
	return $form;
}

/* Page callback for admin/structure/workbench/%/manage-pages/add/subpage */
function idap_workbench_manage_pages_add_subpage($sid) {
	
	$result = db_query('SELECT iw.tid FROM {idap_workbench} iw WHERE iw.sid = :sid', array(':sid'=>$sid));
	
	foreach ($result as $record) {
		$section_tid = $record->tid;
	}
	
	$form_state['values'] = array(
		'tid' => $section_tid,
		'sid' => $sid,
	);
	
	$output = '<h1>Manage Pages: Add Sub-page</h1>';
	$output .= drupal_render(drupal_build_form('idap_workbench_form_create_subpage',&$form_state));
	return $output;
}

/* Add a new term to the 'theme' taxononomy */
function idap_workbench_save_taxonomy_term($parameters) {
	
	$term->vid = 6; // @to do: Hardcoding works for now, but get this dynamically from pid
	$term->name = $parameters['section_title'];
	$term->parent = $parameters['taxonomy_parent'];
	$term->weight = 10;

	taxonomy_term_save($term);
	$tid = $term->tid;
	
	return $tid;
}

/* Create a new carousel node item */
function idap_workbench_store_carousel_node($carousel, $title, $tid) {
	// Create a node object, and add node properties.
	$node = (object) NULL;
	$node->type = 'carousel';
	$node->uid = 0;
	$node->created = strtotime("now");
	$node->changed = strtotime("now");
	$node->status = 1;
	$node->comment = 0;
	$node->promote = 0;
	$node->moderate = 0;
	$node->sticky = 0;
	$node->language = 'und';
	$node->title = $title;
	
	$node->body['und']['0']['value'] = $carousel['body'];
	
	$path = 'taxonomy/term/'.$tid;
	if(module_exists('path')) {
		$path = drupal_get_path_alias($path);
	}
	$node->field_read_more_link['und']['0'] = array(
		'url' => $path,
		'title' => 'Read More &gt;',
		'html' => TRUE,
		'display_url' => $path,
		'attributes' => array(),
	);
	
	$image_file = file_load($carousel['carousel_image']);
	$node->field_carousel_image['und']['0'] = array(
		'fid' => $image_file->fid,
		'filename' => $image_file->filename,
		'uri' => $image_file->uri,
		'filemime' => $image_file->filemime,
		'filesize' => $image_file->filesize,
		'status' => $image_file->status,
		'timestamp' => $image_file->timestamp,
		'rdf_mapping' => $image_file->rdf_mapping,
	);
	
	node_object_prepare($node);
	node_save($node);
	return $node->nid;
}

/* Create a new context to display a block from the 'idap_page_builder' module when this taxonomy term is used */
function idap_workbench_save_page_builder_context($tid, $machine_name) {
	$class = str_replace('_','-',$machine_name).'-section-page';
	
	$context = new stdClass();
	$context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
	$context->api_version = 3;
	$context->name = $machine_name;
	$context->description = '';
	$context->tag = 'Page Builder';
	$context->conditions = array(
	  'node_taxonomy' => array(
	    'values' => array(
	      $tid => $tid,
	    ),
	    'options' => array(
	      'node_form' => '1',
	    ),
	  ),
	);
	$context->reactions = array(
	  'block' => array(
	    'blocks' => array(
	      'idap_page_builder-masthead_banner' => array(
	        'module' => 'idap_page_builder',
	        'delta' => 'masthead_banner',
	        'region' => 'masthead',
	        'weight' => '-10',
	      ),
	    ),
	  ),
	  'menu' => 'taxonomy/term/'.$tid,
	  'theme_html' => array(
	    'class' => $class,
	  ),
	);
	$context->condition_mode = 0;
	
	context_save($context);
}

function idap_workbench_save_page_builder_context_breadcrumb($tid, $machine_name) {
	$context = new stdClass();
	$context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
	$context->api_version = 3;
	$context->name = 'taxonomy_breadcrumb_'.$machine_name;
	$context->description = t('Sets up a breadcrumb to this content');
	$context->tag = 'Breadcrumbs';
	$context->conditions = array(
	  'node' => array(
	    'values' => array(
	      'blog' => 'blog',
	      'carousel' => 'carousel',
	      'e_discussion' => 'e_discussion',
	      'event' => 'event',
	      'group_collaboration' => 'group_collaboration',
	      'media_article' => 'media_article',
	      'network_news' => 'network_news',
	      'resource' => 'resource',
	    ),
	    'options' => array(
	      'node_form' => '1',
	    ),
	  ),
	  'node_taxonomy' => array(
	    'values' => array(
	      $tid => $tid,
	    ),
	    'options' => array(
	      'node_form' => '0',
	    ),
	  ),
	);
	$context->reactions = array(
	  'breadcrumb' => 'taxonomy/term/'.$tid,
	);
	$context->condition_mode = 0;
	
	context_save($context);
}

/* Change the status of temporary uploaded files to permanent */
function store_uploaded_files($fid, $module, $type, $id) {
	
	$file = file_load($fid); // Load the file via file.fid.

	$file->status = FILE_STATUS_PERMANENT; 	// Change status to permanent.
	
	file_save($file); // Save.
	
	file_usage_add($file, $module, $type, $id); // Record that the module (in this example, user module) is using the file.
}

/* Page callback for admin/structure/workbench/%/manage-pages/add/landing-page */
function idap_workbench_manage_pages_add_landing_page($sid) {
	$result = db_query('SELECT iw.tid FROM {idap_workbench} iw WHERE iw.sid = :sid', array(':sid'=>$sid));
	
	foreach ($result as $record) {
		$section_tid = $record->tid;
	}
	
	$form_state['values'] = array(
		'tid' => $section_tid,
		'sid' => $sid,
	);
	
	$output = '<h1>Manage Pages: Section Home Page</h1>';
	$output .= drupal_render(drupal_build_form('idap_workbench_form_create_landing_page',&$form_state));
	return $output;
}

/* Implements hook_form() to route page and subpage creation requests to base form */
function idap_workbench_forms() {
	$items['idap_workbench_form_create_subpage'] = array(
		'callback' => 'idap_workbench_form_create_page',
	);
	$items['idap_workbench_form_create_landing_page'] = array(
		'callback' => 'idap_workbench_form_create_page',
	);
	return $items;
}

/* Form array for form to create a new page */
function idap_workbench_form_create_page($form_id, &$form_state) {
	$form_id = $form_state['build_info']['form_id'];
	
	// Check which form_id is used to call this function and select the page type accordingly
	switch ($form_id) {
		case 'idap_workbench_form_create_subpage':
			$page_type = 'subpage';
			break;
		case 'idap_workbench_form_create_landing_page':
			$page_type = 'landing-page';
			break;
	}
	
	// Get a list of available landing page node types
	$node_types = node_type_get_types();
	$options = array();
	foreach($node_types as $key=>$type) {
		if (fnmatch('content_landing_page_type_*',$key)) {
			$options[$key] = $type->name;
		}
	}

	$form = array();
	$form['page_title'] = array(
		'#title' => t('Page Title'),
		'#type' => 'textfield',
		'#required' => TRUE,
	);
	$form['node_type'] = array(
		'#title' => t('Type of page'),
		'#type' => 'radios',
		'#options' => $options,
		'#required' => TRUE,
	);
	$form['section_id'] = array(
		'#type' => 'hidden',
		'#value' => $form_state['values']['sid'],
	);
	$form['page_theme'] = array(
		'#type' => 'hidden',
		'#value' => $form_state['values']['tid'],
	);
	$form['page_type'] = array(
		'#type' => 'hidden',
		'#value' => $page_type,
	);
	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => 'submit',
		'#title' => t('Create subpage'),
	);
	return $form;
}

/* validation callback for 'idap_workbench_form_create_page' */
function idap_workbench_form_create_page_validate($form, &$form_state) {
	$values = $form_state['values'];
	$page_exists = FALSE;
	
	// Only one landing page is allowed per section, so check if one exists first
	if ($values['page_type'] == 'landing-page') {
		$result = db_query('SELECT iw.tid, iwp.page_type FROM {idap_workbench_pages} iwp LEFT JOIN {idap_workbench} iw ON iwp.sid = iw.sid WHERE iw.tid = :tid AND iwp.page_type = :landing_page', array(':tid'=>$values['page_theme'],':landing_page'=>'landing-page'));
		foreach($result as $row) {
			if ($row) {
				$page_exists = TRUE;
			}
		}
		if ($page_exists) {
			form_set_error('page_theme', t('Sorry, a landing page already exists for this section. You must delete the existing one before you can create a new one.'));
		}
	}
	
}

/* submit callback for 'idap_workbench_form_create_page */
function idap_workbench_form_create_page_submit($form, &$form_state) {
	$values = $form_state['values'];
	$values['page_nid'] = idap_workbench_store_page_node($values['node_type'], $values['page_title'], $values['page_theme']);
	
	if ($values['page_type'] == 'landing-page') {
		//Create redirect from taxonomy page to landing page node
		idap_workbench_redirect_save($values);
	}
	
	$values['page_type'] == 'landing-page' ? $values['menu_weight'] = -100 : $values['menu_weight'] = 0;
	
	$values['mlid'] = idap_workbench_menu_link_save($values);
	
	$nid = db_insert('idap_workbench_pages') // Table name no longer needs {}
	->fields(array(
	  'sid' => $values['section_id'],
	  'page_type' => $values['page_type'],
	  'page_title' => $values['page_title'],
	  'node_type' => $values['node_type'],
	  'page_nid' => $values['page_nid'],
	  'mlid' => $values['mlid'],
	))
	->execute();
	
	drupal_set_message(t('Create a new page called '.$values['page_title']));
}

/* Save a new link in the menu */
function idap_workbench_menu_link_save($values) {
	$menu_link = array(
	    'link_title' => $values['page_title'], 
        'link_path' => 'node/'.$values['page_nid'], 
        'menu_name' => 'main_menu',
		'weight' => $values['menu_weight'],
	);
	
	$parent_path = 'taxonomy/term/'.$values['page_theme'];
	
	$result = db_query('SELECT m.mlid FROM {menu_links} m WHERE link_path = :parent_path', array(':parent_path'=>$parent_path));
	foreach($result as $row) {
		$menu_link['plid'] = $row->mlid;
	}
	$mlid = menu_link_save($menu_link);
	menu_cache_clear_all();
	
	return $mlid;
}

/* Save a new redirect from 'theme' taxonomy term to the landing page node */
function idap_workbench_redirect_save($values) {

	$redirect->rid = NULL;
	$redirect->type = 'redirect';
	$redirect->hash = '';
	$redirect->source = 'taxonomy/term/'.$values['page_theme'];
	$redirect->source_options = array();
	$redirect->redirect = 'node/'.$values['page_nid'];
	$redirect->redirect_options = array();
	$redirect->language = 'und';
	$redirect->status_code = 0;
	$redirect->override = FALSE;
	
	redirect_save($redirect);
}

/* Store a new page node (landing page or subpage) */
function idap_workbench_store_page_node($page_type, $title, $tid) {
	// Create a node object, and add node properties.
	$node = (object) NULL;
	$node->type = $page_type;
	$node->uid = 0;
	$node->created = strtotime("now");
	$node->changed = strtotime("now");
	$node->status = 1;
	$node->comment = 0;
	$node->promote = 0;
	$node->moderate = 0;
	$node->sticky = 0;
	$node->language = 'und';
	$node->title = $title;
	
	$path = 'taxonomy/term/'.$tid;
	$node->field_theme['und']['0']['tid'] = $tid;
	
	node_object_prepare($node);
	node_save($node);
	return $node->nid;
}