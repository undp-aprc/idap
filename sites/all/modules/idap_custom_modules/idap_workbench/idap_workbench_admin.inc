<?php

function idap_workbench_add() {
	$form = drupal_get_form('idap_workbench_form_theme_section');
	return $form;
}

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
		 '#default_value' => variable_get('carousel_image'),
		 '#upload_location' => 'public://thematic_sections/carousel_images/',
	);
	$form['submit'] = array(
	    '#type' => 'submit', 
	    '#value' => t('Create Section'),
	  );

	$form['#submit'][] = 'idap_workbench_form_theme_section_submit_new';
		
	return $form;
}

function idap_workbench_form_theme_section_submit_new($form, &$form_state) {
	
	$variables['section_title'] = $form_state['values']['title']; //Section title
	
	$variables['machine_name'] = $form_state['values']['machine_name'];
	
	$variables['taxonomy_parent'] = $form_state['values']['taxonomy_parent'];
	
	$variables['tid'] = idap_workbench_save_taxonomy_term($variables); //Taxonomy term
	
	$variables['carousel_nid'] = idap_workbench_store_carousel_node($form_state['values']['carousel'], $variables['section_title'], $variables['tid']); //Store carousel node
	
	$variables['carousel_fid'] = $form_state['values']['carousel']['carousel_image'];
	
	$variables['banner_fid'] = $form_state['values']['banner_image'];
	
	idap_workbench_save_page_builder_context($variables['tid'], $variables['machine_name']); //Create a context for this section
	
	//Write values to idap_workbench
	$variables['sid'] = db_insert('idap_workbench') // Table name no longer needs {}
	->fields(array(
	  'title' => $variables['section_title'],
	  'machine_name' => $variables['machine_name'],
	  'tid' => $variables['tid'],
	  'pid' => $variables['taxonomy_parent'],
	  'carousel_nid' => $variables['carousel_nid'],
	  'banner_fid' => $variables['banner_fid'],
	))
	->execute();
	
	store_uploaded_files($variables['carousel_fid'], 'node', 'node',  $variables['carousel_nid']); //Update file status of carousel image
	store_uploaded_files($variables['banner_fid'], 'idap_workbench', 'section_banner	',  $variables['banner_fid']); //Update file status of carousel image
	
	drupal_set_message(t('Successfully created a new thematic section'));
}