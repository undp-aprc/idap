<?php
/* Page Callbacks */

/* Page Callback for admin/structure/workbench */
function idap_workbench_list() {
	$output = '<h1>Sections Overview</h1>'; 
	$output .= theme('table', idap_workbench_list_view_table());
	return $output;
}

/* theme_table array to display the list of sections on admin/structure/workbench */
function idap_workbench_list_view_table() {
	$table = array();
	$table['header'] = array(
		'title' => array(
			'data' => t('Section Title'),
			'class' => array(
				'table-title',
			),
		),
		'pillar' => array(
			'data' => t('Pillar'),
		),
		'operations' => array(
			'data' => t('Operations'),
			'colspan' => 4,
			'class' => 'table-operations'
		),
	);
	
	$result = db_query('SELECT * FROM {idap_workbench} iw ORDER by iw.pid');
	
	foreach($result as $row) {
		$variables[$row->sid]['sid'] = $row->sid;
		$variables[$row->sid]['title'] = $row->title;
		$variables[$row->sid]['pid'] = $row->pid;
		$variables[$row->sid]['tid'] = $row->tid;
		
		$table['rows'][] = array(
			array(
				'data' => l($row->title, 'taxonomy/term/'.$row->tid, array()),
				'class' => 'table-cell-title',
			),
			array(
				'data' => !empty($row->pid) ? taxonomy_term_load($row->pid)->name : NULL,
				'class' => 'table-cell-pillar',
			),
			array(
				'data' => l(t('Manage Pages'),'admin/structure/workbench/'.$row->sid.'/manage-pages', array()),
				'class' => 'table-operations-add',
			),
			array(
				'data' => l(t('Edit Section'),'admin/structure/workbench/'.$row->sid.'/edit', array()),
				'class' => 'table-operations-edit',
			),
			array(
				'data' => l(t('Delete Section'),'admin/structure/workbench/'.$row->sid.'/delete', array()),
				'class' => 'table-operations-delete',
			),
		);
	}
	
	return $table;
}

/* Page callback for admin/structure/workbench/%/manage-pages */
/* @To Do: Needs review -- separate structure from HTML */
function idap_workbench_manage_pages($sid) {
	$result = db_query('SELECT iw.sid, iw.title, iw.tid, iwp.sid, iwp.page_type, iwp.page_title, iwp.node_type, iwp.page_nid FROM {idap_workbench} iw LEFT JOIN {idap_workbench_pages} iwp ON iw.sid = iwp.sid WHERE iw.sid = :sid', array(':sid'=>$sid));
	
	$table = array();
	$table_landing_page['header'] = array(
		'title' => array(
			'data' => t('Page Title'),
			'class' => array(
				'table-title',
			),
			'style' => array(
				'width:50%;'
			),
		),
		'operations' => array(
			'data' => t('Operations'),
			'colspan' => 2,
			'class' => 'table-operations',
			'style' => array(
				'text-align:center;'
			),
		),
	);
	$table_subpage['header'] = array(
		'title' => array(
			'data' => t('Page Title'),
			'class' => array(
				'table-title',
			),
			'style' => array(
				'width:50%;'
			),
		),
		'operations' => array(
			'data' => t('Operations'),
			'colspan' => 2,
			'class' => 'table-operations',
			'style' => array(
				'text-align:center;'
			),
		),
	);
	
	foreach($result as $row) {
		$title = $row->title;
		if ($row->page_type == 'landing-page') {
			$table_landing_page['rows'][] = array(
				array(
					'data' => l($row->page_title, 'node/'.$row->page_nid, array()),
					'class' => 'table-cell-page-title',
				),
				array(
					'data' => l(t('Edit Page'),'node/'.$row->page_nid.'/edit', array()),
					'class' => 'table-operations-page-edit',
					'style' => array(
						'text-align:center;'
					),
				),
				array(
					'data' => l(t('Delete Page'),'node/'.$row->page_nid.'/delete', array()),
					'class' => 'table-operations-edit',
					'style' => array(
						'text-align:center;'
					),
				),
			);	
		}
		if ($row->page_type == 'subpage') {
			$table_subpage['rows'][] = array(
				array(
					'data' => l($row->page_title, 'node/'.$row->page_nid, array()),
					'class' => 'table-cell-page-title',
				),
				array(
					'data' => l(t('Edit Page'),'node/'.$row->page_nid.'/edit', array()),
					'class' => 'table-operations-page-edit',
					'style' => array(
						'text-align:center;'
					),
				),
				array(
					'data' => l(t('Delete Page'),'node/'.$row->page_nid.'/delete', array()),
					'class' => 'table-operations-edit',
					'style' => array(
						'text-align:center;'
					),
				),
			);	
		}
	}
	$output = '<h1>Pages in section: '.$title.'</h1>';
	$output .= '<div style="height:20px;"></div>';
	$output .= '<h2>Section Home Page</h2>';
	$output .= theme('table',$table_landing_page);
	$output .= '<h2>Section Subpages</h2>';
	$output .= theme('table',$table_subpage);
	return $output;
}

/* Validate callback for idap_form_theme_section */
function idap_workbench_form_theme_section_validate($form, &$form_state) {
	// Validation functions
}

/* Submit callback for idap_workbench_form_theme_section */
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