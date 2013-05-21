<?php
/**
 * @file
 * feature_blog.features.inc
 */

/**
 * Implements hook_node_info().
 */
function feature_blog_node_info() {
  $items = array(
    'blog' => array(
      'name' => t('Blog'),
      'base' => 'node_content',
      'description' => t('Reflective and analytical articles written by members of the community.'),
      'has_title' => '1',
      'title_label' => t('Article Title'),
      'help' => '',
    ),
  );
  return $items;
}
