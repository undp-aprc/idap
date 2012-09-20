<?php

function idap_workbench_load_taxonomy_vocab($theme = 'themes') {
	if ($vocabulary = taxonomy_vocabulary_machine_name_load('themes')) {
		if ($terms = taxonomy_get_tree($vocabulary->vid)) {
	    	foreach ($terms as $term) {
				if ($term->depth == 0) { // Only display the top level
					$themes[$term->tid] = $term->name;
			  	}
	        }
		}
	}

	return $themes;
}

function idap_workbench_save_taxonomy_term($parameters) {
	
	$term->vid = 6; // @to do: Hardcoding works for now, but get this dynamically from pid
	$term->name = $parameters['section_title'];
	$term->parent = $parameters['taxonomy_parent'];
	$term->weight = 10;

	taxonomy_term_save($term);
	$tid = $term->tid;
	
	return $tid;
}

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

function idap_workbench_save_page_builder_context($tid, $machine_name) {
	$class = str_replace('_','-',$machine_name).'-section-page';
	
	$context = new stdClass();
	$context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
	$context->api_version = 3;
	$context->name = $machine_name;
	$context->description = '';
	$context->tag = '';
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

function section_name_exists($machine_name) {
	/* To do: check this value against database to ensure it's unique */
	return FALSE;
}

function store_uploaded_files($fid, $module, $type, $id) {
	
	$file = file_load($fid); // Load the file via file.fid.

	$file->status = FILE_STATUS_PERMANENT; 	// Change status to permanent.
	
	file_save($file); // Save.
	
	file_usage_add($file, $module, $type, $id); // Record that the module (in this example, user module) is using the file.
}