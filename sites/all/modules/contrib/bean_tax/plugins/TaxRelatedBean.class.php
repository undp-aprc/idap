<?php
/**
 * @file
 * Taxonomy Related Entities bean plugin.
 */

class TaxRelatedBean extends BeanPlugin {

  /**
   * Declares default block settings.
   */
  public function values() {
    return array(
      'view_mode' => 'default',
      'filters' => array(
        'vocabulary' => FALSE,
        'records_shown' => 5,
        'offset_results' => 0,
      ),
      'settings' => array(
        'related' => 'page',
        'entity_type' => 'node',
        'bundle_types' => FALSE,
        'entity_view_mode' => FALSE,
        'hide_empty' => FALSE,
        'unmatch_add' => FALSE,
      ),
      'more_link' => array(
        'text' => '',
        'path' => '',
      ),
    );
  }

  /**
   * Builds extra settings for the block edit form.
   */
  public function form($bean, $form, &$form_state) {

    // Here we are defining the form.
    $form = array();

    // Settings fieldset is used for configuring the 'related' bean output.
    $form['settings'] = array(
      '#type' => 'fieldset',
      '#tree' => TRUE,
      '#title' => t('Output'),
      '#prefix' => '<div id="output-wrapper">',
      '#suffix' => '</div>',
    );

    // Instantiate entity info.
    $entity_info = entity_get_info();

    // Create a list of entity types that have view modes.
    $entity_types = array();
    foreach ($entity_info as $key => $value) {
      if (!empty($value['view modes'])) {
        $entity_types[$key] = $key;
      }
    }

    // User select how entites are related.
    $form['settings']['related'] = array(
      '#type' => 'select',
      '#title' => t('Related To'),
      '#options' => array(
        'page' => 'Active Page',
        'user' => 'Logged-in User',
      ),
      '#default_value' => $bean->settings['related'],
      '#required' => TRUE,
      '#multiple' => FALSE,
    );

    // User select which entity type to use for output.
    $form['settings']['entity_type'] = array(
      '#type' => 'select',
      '#title' => t('Entity Type'),
      '#options' => $entity_types,
      '#default_value' => $bean->settings['entity_type'],
      '#required' => TRUE,
      '#multiple' => FALSE,
      '#ajax' => array(
        'callback' => 'bean_tax_entity_type_callback',
        'wrapper' => 'output-wrapper',
        'method' => 'replace',
      ),
    );

    // Check for an ajax update and use new entity_type setting.
    if (!isset($form_state['values']['settings']['entity_type'])) {
      $entity_type = $bean->settings['entity_type'];
    }
    else {
      $entity_type = $form_state['values']['settings']['entity_type'];
    }

    // User select which view mode to use for the results inside the bean.
    $form['settings']['entity_view_mode'] = array(
      '#type' => 'select',
      '#title' => t('Entity View Mode'),
      '#options' => bean_tax_get_entity_view_modes($entity_info, $entity_type),
      '#default_value' => $bean->settings['entity_view_mode'],
      '#required' => TRUE,
      '#multiple' => FALSE,
    );

    // Determine what entity bundle types to display.
    $form['settings']['bundle_types'] = array(
      '#type' => 'select',
      '#title' => t('Entity Bundles'),
      '#options' => bean_tax_get_entity_bundles($entity_type),
      '#default_value' => $bean->settings['bundle_types'],
      '#required' => TRUE,
      '#multiple' => TRUE,
      '#size' => 5,
    );

    $form['settings']['hide_empty'] = array(
      '#type' => 'checkbox',
      '#title' => t('Do not display block if there are no results.'),
      '#default_value' => $bean->settings['hide_empty'],
    );
    
    $form['settings']['unmatch_add'] = array(
      '#type' => 'checkbox',
      '#title' => t('Append unrelated entities so there are more results.'),
      '#default_value' => $bean->settings['unmatch_add'],
    );

    // Select objects for the vocabularies that will be used.
    $vocabulary = taxonomy_get_vocabularies();
    $select_vocabulary_array = array();
    foreach ($vocabulary as $item) {
      $key = $item->vid;
      $value = $item->name;
      $select_vocabulary_array[$key] = $value;
    }

    // Define the filters fieldset.
    $form['filters'] = array(
      '#type' => 'fieldset',
      '#tree' => TRUE,
      '#title' => t('Filters'),
    );

    // User define a maximum number of entities to be shown.
    $form['filters']['records_shown'] = array(
      '#type' => 'textfield',
      '#title' => t('Records shown'),
      '#size' => 5,
      '#default_value' => $bean->filters['records_shown'],
      '#element_validate' => array('bean_tax_setting_is_numeric'),
    );
   
    // User define a maximum number of entities to be shown.
    $form['filters']['offset_results'] = array(
      '#type' => 'textfield',
      '#title' => t('Offset Results'),
      '#size' => 5,
      '#default_value' => $bean->filters['offset_results'],
      '#element_validate' => array('bean_tax_setting_is_numeric'),
    );

    // Determine related taxonomy term vocabularies.
    $form['filters']['vocabulary'] = array(
      '#type' => 'select',
      '#title' => t('Vocabularies'),
      '#options' => $select_vocabulary_array,
      '#default_value' => $bean->filters['vocabulary'],
      '#required' => TRUE,
      '#multiple' => TRUE,
      '#size' => 5,
    );

    // Define a "read more" style link to be shown at the bottom of the bean.
    $form['more_link'] = array(
      '#type' => 'fieldset',
      '#tree' => TRUE,
      '#title' => t('More link'),
    );

    // Link text shown on the 'more link' to be defined by user.
    $form['more_link']['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Link text'),
      '#default_value' => $bean->more_link['text'],
    );

    // Actual URL path for the 'more link' defined by user.
    $form['more_link']['path'] = array(
      '#type' => 'textfield',
      '#title' => t('Link path'),
      '#default_value' => $bean->more_link['path'],
    );
    return $form;
  }

  /**
   * Displays the bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {

    // We need to make sure that the bean is configured correctly.
    if (!empty($bean->filters['vocabulary']) && !empty($bean->settings['bundle_types'])) {

      // Define an array of all taxonomy terms in the defined vocabularies.
      $possible_tid = array();
      foreach ($bean->filters['vocabulary'] as $vid) {
        $tree = taxonomy_get_tree($vid);
        foreach ($tree as $term) {
          array_push($possible_tid, $term->tid);
        }
      }

      // Compare possible terms to those attached to the menu object or current
      // user depending on 'related' settings.
      $active_entity = bean_tax_active_entity_array($bean->settings['related']);
      if (isset($active_entity['terms'])) {
        $valid_tid = array();
        foreach ($active_entity['terms'] as $term) {
          if (in_array($term->tid, $possible_tid)) {
            array_push($valid_tid, $term->tid);
          }
        }

        // Entity field query for nodes of the defined content types (bundle).
        $aggregate = array();
        foreach ($bean->settings['bundle_types'] as $bundle) {
          $query = new EntityFieldQuery();
          $query->entityCondition('entity_type', $bean->settings['entity_type']);
          $query->entityCondition('bundle', $bundle);
          if ($bean->settings['entity_type'] == 'node') {
            $query->propertyCondition('status', 1);
          }
          $result[$bundle] = $query->execute();

          // Store the results in an aggregated array of entities.
          if (!empty($result[$bundle])) {
            $aggregate = $aggregate + $result[$bundle];
          }
        }

        // Create a taxonomy related "score" for each result's matching terms.
        $result = array();
        $unmatching = array();
        foreach ($aggregate[$bean->settings['entity_type']] as $key => $value) {
          $entity_terms = bean_tax_get_entity_terms($bean->settings['entity_type'], $key);
          $score = 0;
          // The actual scoring to determine valid taxonomy term matching.
          foreach ($entity_terms as $term) {
            if (in_array($term->tid, $valid_tid)) {
              $score++;
            }
          }
          $item['id'] = $key;
          $item['score'] = $score;
          // A score of 1 or greater adds to the array of matching entities.
          if ($score != 0) {
            array_push($result, $item);
          }
          elseif ($score == 0 && $bean->settings['unmatch_add'])  {
            array_push($result, $item);
          }
        }
        // Invoke comparison function to determine highest ranked results.
        usort($result, "bean_tax_cmp");
      }

      // Remove active page from results.
      if(!empty($result)) {
        foreach ($result as $key => $entity) {
          $active_page = bean_tax_active_entity_array('page');
          if (isset($active_page['ids']) && $active_page['ids'][0] == $entity['id'] && $active_page['type'] == $bean->settings['entity_type']) {
            unset($result[$key]);
          }
        }
      }
      // Return something when viewing the bean page callback.
      if (isset($active_entity['type']) && $active_entity['type'] == 'bean' && $bean->bid === $active_entity['object']->bid) {
        $content['#markup'] = '';
      }
      // Related entities initially set to none.
      elseif (empty($result)) {
        // Hide block when result is empty and 'hide_empty' option is checked.
        if ($bean->settings['hide_empty'] || !$active_entity['object']) return;
        // There are no related nodes. Set Empty array for theme output.
        $content['#markup'] = t('No Results');
      }
      else {
        // Start counting results at index of 0.
        $i = 0;
        // Set and index for actual results shown.
        $shown = 0;
        // Set markup index as empty.
        $content['#markup'] = '';
        // Load and render the related entities.
        foreach ($result as $entity) {
          if ($shown < $bean->filters['records_shown'] && $i >= $bean->filters['offset_results']) {
            $entity = entity_load_single($bean->settings['entity_type'], $entity['id']);
            $entity_view = entity_view($bean->settings['entity_type'], array($entity), $bean->settings['entity_view_mode']);
            $content['#markup'] .= drupal_render($entity_view);
            $shown++;
          }
          // Count continues along...
          $i++;
        }
      }
    }
    // Invoke the theme function to show the additional information "more link"
    $content['more_link']['#markup'] = theme('bean_tax_more_link', array('text' => $bean->more_link['text'], 'path' => $bean->more_link['path']));
    return $content;
  }
}
