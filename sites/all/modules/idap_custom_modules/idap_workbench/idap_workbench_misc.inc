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

function section_name_exists($machine_name) {
	/* To do: check this value against database to ensure it's unique */
	return FALSE;
}

/* Implements hook_node_update() */
/* Updates the idap_workbench_pages table with new data, if a node referenced from the table is updated */
function idap_workbench_node_update($node) {
	if ($node->title != $node->original->title) {
		db_update('idap_workbench_pages') // Table name no longer needs {}
		  ->fields(array(
		    'page_title' => $node->title,
		  ))
		  ->condition('page_nid', $node->nid, '=')
		  ->execute();
	}
}
?>