<?php
/**
 * @file
 * content_landing_pages.features.inc
 */

/**
 * Implements hook_node_info().
 */
function content_landing_pages_node_info() {
  $items = array(
    'content_landing_page_type_1' => array(
      'name' => t('Content Landing Page - Type 1'),
      'base' => 'node_content',
      'description' => t('Create a landing page to display a summary of content.'),
      'has_title' => '1',
      'title_label' => t('Page Title'),
      'help' => '',
    ),
    'content_landing_page_type_2' => array(
      'name' => t('Content Landing Page - Type 2'),
      'base' => 'node_content',
      'description' => t('Create a landing page to display a summary of content.'),
      'has_title' => '1',
      'title_label' => t('Page Title'),
      'help' => '',
    ),
    'content_landing_page_type_3' => array(
      'name' => t('Content Landing Page - Type 3'),
      'base' => 'node_content',
      'description' => t('Create a landing page to display a summary of content.'),
      'has_title' => '1',
      'title_label' => t('Page Title'),
      'help' => '',
    ),
    'content_landing_page_type_4' => array(
      'name' => t('Content Landing Page - Type 4'),
      'base' => 'node_content',
      'description' => t('Create a landing page to display a summary of content.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
