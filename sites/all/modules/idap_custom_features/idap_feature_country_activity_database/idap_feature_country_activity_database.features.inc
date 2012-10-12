<?php
/**
 * @file
 * idap_feature_country_activity_database.features.inc
 */

/**
 * Implements hook_node_info().
 */
function idap_feature_country_activity_database_node_info() {
  $items = array(
    'country_activity' => array(
      'name' => t('Country Activity'),
      'base' => 'node_content',
      'description' => t('Add an entry in the Country Initiatives Database'),
      'has_title' => '1',
      'title_label' => t('Name of this activity'),
      'help' => '',
    ),
  );
  return $items;
}
