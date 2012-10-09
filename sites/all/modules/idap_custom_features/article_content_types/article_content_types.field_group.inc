<?php
/**
 * @file
 * article_content_types.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function article_content_types_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_photo_container|node|network_news|full';
  $field_group->group_name = 'group_photo_container';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'network_news';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Photo Container',
    'weight' => '2',
    'children' => array(
      0 => 'field_photo',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Photo Container',
      'instance_settings' => array(
        'classes' => 'photo-container',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_photo_container|node|network_news|full'] = $field_group;

  return $export;
}
