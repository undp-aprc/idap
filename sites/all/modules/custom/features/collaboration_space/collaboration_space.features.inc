<?php
/**
 * @file
 * collaboration_space.features.inc
 */

/**
 * Implements hook_node_info().
 */
function collaboration_space_node_info() {
  $items = array(
    'group_collaboration' => array(
      'name' => t('Collaboration Space'),
      'base' => 'node_content',
      'description' => t('Create a space where group members can share content. The space may be either open to the public or closed and accessible to members only. You can control who has access to the space.'),
      'has_title' => '1',
      'title_label' => t('Collaboration Space Name'),
      'help' => '',
    ),
  );
  return $items;
}
