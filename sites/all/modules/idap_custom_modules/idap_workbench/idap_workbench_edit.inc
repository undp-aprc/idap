<?php
function idap_workbench_section_edit($sid) {
	$section_values = idap_workbench_fetch_theme_section($sid);	
	$form_state = array();
	$form_state['values']['sid'] = $section_values->sid;
	$form_state['values']['title'] = $section_values->title;
	$form_state['values']['machine_name'] = $section_values->machine_name;
	$form_state['values']['tid'] = $section_values->tid;
	$form_state['values']['taxonomy_parent'] = $section_values->pid;
	$form_state['values']['banner_fid'] = $section_values->banner_fid;
	
	$form = drupal_build_form('idap_workbench_form_edit_theme_section', &$form_state);
	return $form;
}

/* Form array for 'idap_workbench_form_theme_section' */
function idap_workbench_form_edit_theme_section($form, &$form_state) {
	$form['sid'] = array(
		'#type' => 'hidden',
		'#default_value' => $form_state['values']['sid'],
	);
	$form['tid'] = array(
		'#type' => 'hidden',
		'#default_value' => $form_state['values']['tid'],
	);
	$form['machine_name_old'] = array(
		'#type' => 'hidden',
		'#default_value' => $form_state['values']['machine_name'],
	);
	$form['title'] = array(
		'#type' => 'textfield',
		'#title' => t('Section Title'),
		'#required' => TRUE,
		'#default_value' => $form_state['values']['title'],
	);
	$form['machine_name'] = array(
		'#type' => 'machine_name',
		'#machine_name' => array(
			'source' => array('title'),
			'label' => t('Machine Name'),
			'exists' => 'section_name_exists'
		),
		'#default_value' => $form_state['values']['machine_name'],
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
		'#default_value' => $form_state['values']['taxonomy_parent'],
	);
	$form['section']['banner_image'] = array(
		'#title' => t('Banner Image'),
		 '#type' => 'managed_file',
		 '#description' => t('This image must be 983 pixels wide by 150 pixels high.'),
		 '#default_value' => intval($form_state['values']['banner_fid']),
		 '#upload_location' => 'public://thematic_sections/banner_images/',
		 '#required' => TRUE,
	);
	$form['submit'] = array(
	    '#type' => 'submit', 
	    '#value' => t('Update Section'),
	  );

	$form['#submit'][] = 'idap_workbench_form_theme_section_submit_edit';
	$form['#redirect'] = 'admin/structure/workbench';	
	return $form;
}

function idap_workbench_form_theme_section_submit_edit($form, &$form_state) {
	dsm($form_state);
	$sid = $form_state['values']['sid'];
	$tid = $form_state['values']['tid'];
	
	if ($form_state['values']['machine_name'] != $form_state['values']['machine_name_old']) { //Machine name has changed
		//Delete the old entries
		db_delete('context')->condition('name','masthead_'.$form_state['values']['machine_name_old'])->execute();
		db_delete('context')->condition('name','taxonomy_breadcrumb_'.$form_state['values']['machine_name_old'])->execute();
		
		//Create new entries
		idap_workbench_save_page_builder_context($tid, $form_state['values']['machine_name']); //Create a context for this section
		idap_workbench_save_page_builder_context_breadcrumb($tid, $form_state['values']['machine_name']); //Create a breadcrumb context for this section
	}
	
	$term = taxonomy_term_load($tid);
	$term->name = $form_state['values']['title'];
	$term->parent = $form_state['values']['taxonomy_parent'];
	taxonomy_term_save($term);
	
	$rows_updated = db_update('idap_workbench') 
	->fields(array(
	  'title' => $form_state['values']['title'],
	  'machine_name' => $form_state['values']['machine_name'],
	  'pid' => $form_state['values']['taxonomy_parent'],	
	  'banner_fid' => $form_state['values']['banner_image'],
	))
	->condition('idap_workbench.sid', $sid, '=')
	->execute();
	
	store_uploaded_files($form_state['values']['banner_image'], 'idap_workbench', 'section_banner',  $sid); //Update file status of banner image
	
	drupal_goto('admin/structure/workbench/'.$sid);
	drupal_set_message(t('Successfully updated this section'));
}
?>