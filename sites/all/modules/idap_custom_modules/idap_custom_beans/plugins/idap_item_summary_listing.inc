<?php
/**
 * @file
 * Listing bean plugin.
 */

class IDAPItemSummaryListing extends BeanPlugin {
  /**
   * Declares default block settings.
   */
  public function values() {
    return array(
      'settings' => array(
        'node_view_mode' => FALSE,
        'records_shown' => FALSE,
      ),
      'more_link' => array(
        'text' => '',
        'path' => '',
      ),
	  'filters' => array(
        'themes' => '',
        'countries' => '',
		'types' => '',
      ),
    );
  }
	
  /**
   * Builds extra settings for the block edit form.
   */
  public function form($bean, $form, &$form_state) {
    $form = array();

	$form['label'] = array(
	    '#type' => 'textfield',
	    '#title' => t('Label'),
	    '#required' => TRUE,
	    '#default_value' => $bean->label,
	    '#description' => t('The name of the block that will be displayed in the administration interface'),
	    '#weight' => -10,
	  );

	  $form['title'] = array(
	    '#type' => 'textfield',
	    '#title' => t('Title'),
	    '#description' => t('The title of the block that will be displayed in public areas where the block is placed.'),
	    '#default_value' => $bean->title,
	    '#weight' => -9,
	  );

	  // The view mode
	    $form['view_mode'] = array(
	      '#type' => 'value',
	      '#value' => 'default',
	    );

	/* Override defaults in bean.pages.inc */
    $form['settings'] = array(
      '#type' => 'fieldset',
      '#tree' => 1,
      '#title' => t('Output'),
    );
    $node_view_modes = array();
    $entity_info = entity_get_info();
    foreach ($entity_info['node']['view modes'] as $key => $value) {
      $node_view_modes[$key] = $value['label'];
    }
    if (!isset($bean->settings['node_view_mode'])) {
      $default_node_view_mode = 'teaser_bullets';
    }
    else {
      $default_node_view_mode = $bean->settings['node_view_mode'];
    }
    $form['settings']['node_view_mode'] = array(
      '#type' => 'select',
      '#title' => t('Node View Mode'),
      '#options' => $node_view_modes,
      '#default_value' => $default_node_view_mode,
      '#required' => TRUE,
      '#multiple' => FALSE,
    );
    if (!$records_shown = $bean->settings['records_shown']) {
      $records_shown = 5;
    }

	/** Define some additional options **/
	if ($vocabulary = taxonomy_vocabulary_machine_name_load('themes')) {
		if ($terms = taxonomy_get_tree($vocabulary->vid)) {
	    	foreach ($terms as $term) {
				if ($term->depth > 0) { // Don't display the top level, these are pillars and we don't want to assign any content there
					$themes[$term->tid] = $term->name;
			  	}
	        }
		}
	}
	
	$types = node_type_get_types();
	$type_options = array();
	foreach($types as $machine_name=>$value) {
		$type_options[$machine_name] = $types[$machine_name]->name;
	}
		
    $form['settings']['records_shown'] = array(
      '#type' => 'textfield',
      '#title' => t('Records shown'),
      '#size' => 5,
      '#default_value' => $records_shown,
	  '#description' => t('Enter 0 for unlimited records'),
    );
    $form['more_link'] = array(
      '#type' => 'fieldset',
      '#tree' => 1,
      '#title' => t('More link'),
    );
    $form['more_link']['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Link text'),
      '#default_value' => $bean->more_link['text'],
    );
    $form['more_link']['path'] = array(
      '#type' => 'textfield',
      '#title' => t('Link path'),
      '#default_value' => $bean->more_link['path'],
    );
	$form['filters'] = array(
      '#type' => 'fieldset',
      '#tree' => 1,
      '#title' => t('Content Filter'),
	  '#description' => t('These options allow you to specify the type of content that is displayed in this block'),
    );
	$form['filters']['types'] = array(
	      '#type' => 'select',
	      '#title' => t('Select a content type'),
	      '#description' => t('Choose the type of content you wish to list in this block.'),
	      '#options' => $type_options,
	      '#default_value' => $bean->filters['types'],
	      '#multiple' => FALSE,
	      '#size' => 10,
		  '#required' => TRUE,
	    );
    return $form;
  }

  /**
   * Displays the bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
    $query = new IDAPEntityFieldQuery();
    $query
      ->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', array($bean->filters['types']))
      ->propertyCondition('status', 1)
      ->propertyOrderBy('created', 'DESC');

	if ($bean->settings['records_shown'] > 0) {
		$query->range(0, $bean->settings['records_shown']);
	}

	if($node = menu_get_object()) {
		if(isset($node->group_group)) { // Filter by group take precendence over filter by theme
			if($node->group_group['und']['0']['value'] == 1) {
				$query->SetGroupContentCondition($node->nid);
			}
		} elseif($tid = $node->field_theme['und']['0']['tid']) {
			$query->SetContentTermCondition($tid); 
		};
	};

    $result = $query->execute();
    if (empty($result)) {
      $content['nodes'] = array();
    }
    else {
      foreach ($result['node'] as $node) {
        $node = node_load($node->nid, $node->vid);
		if (node_access('view',$node)) { // Check if current user has access to a node. If not, then don't add to node listing
			$content['nodes'][$node->nid] = node_view($node, $bean->settings['node_view_mode']);
		}
      }
    }
    return $content;
  }
}