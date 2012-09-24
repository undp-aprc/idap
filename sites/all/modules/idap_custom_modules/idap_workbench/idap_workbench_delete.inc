<?php
/* Page callback for admin/structure/workbench/%/delete */
function idap_workbench_section_delete($sid) {
	$form_state['values']['sid'] = $sid;
	
	$form = drupal_build_form('idap_workbench_confirm_delete', $form_state);
	
	$output = '<p>Confirm you would like to delete this section -- this cannot be reversed. The content associated with this theme will <em>not</em> be deleted, but it may be difficult for users to find this content because the content because it will no longer be associated with any section of the site.</p>';
	$output .= drupal_render($form);
	return $output;
}

function idap_workbench_confirm_delete($form_id, &$form_state) {
	$values = $form_state['values'];
	
	$form['sid'] = array(
		'#type' => 'hidden',
		'#value' => $values['sid'],
	);
	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Delete this section'),
	);
	$form['#redirect'] = 'admin/structure/workbench';
	
	return $form;
}

function idap_workbench_confirm_delete_submit($form, &$form_state) {
	foreach(db_query('SELECT * FROM {idap_workbench} iw WHERE iw.sid = :sid', array(':sid'=>$form_state['values']['sid'])) as $row) {
		
		// Delete the carousel item
		$carousel_node_delete = node_delete($row->carousel_nid);
		
		// Delete taxonomy term
		$taxonomy_term_delete = taxonomy_term_delete($row->tid);
		
		// Delete context to display banner block
		$context = context_load($row->machine_name);
		$context_delete = context_delete($context);
		
		//Delete menu link
		$path = 'taxonomy/term/'.$row->tid;
		$menu_link_delete = menu_link_delete(NULL, $path);
	}
	
	foreach(db_query('SELECT * FROM {idap_workbench_pages} iwp WHERE iwp.sid = :sid', array(':sid'=>$form_state['values']['sid'])) as $row) {
		// Delete all the landing page nodes in this section
		$node_delete = node_delete($row->page_nid);
	}
	
	// Remove section from workbench
	$deleted_rows = db_delete('idap_workbench')
	  ->condition('sid', $form_state['values']['sid'], '=')
	  ->execute();
	
	$deleted_rows = db_delete('idap_workbench_pages')
	  ->condition('sid', $form_state['values']['sid'], '=')
	  ->execute();
	
	drupal_set_message(t('The section was deleted successfully'));
}

/* Implements hook_node_delete() */
/* Deletes a page from idap_workbench_pages if a node referenced by this table is deleted */
function idap_workbench_node_delete($node) {
	$num_deleted = db_delete('idap_workbench_pages')
	  ->condition('page_nid', $node->nid)
	  ->execute();
}

