<?php
/**
 * @file
 * collaboration_space.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function collaboration_space_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'body'
  $field_bases['body'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'node',
    ),
    'field_name' => 'body',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 1,
    'type' => 'text_with_summary',
  );

  // Exported field_base: 'field_block_1'
  $field_bases['field_block_1'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_block_1',
    'foreign keys' => array(
      'bid' => array(
        'columns' => array(
          'bid' => 'bid',
        ),
        'table' => 'block',
      ),
    ),
    'indexes' => array(
      'bid' => array(
        0 => 'bid',
      ),
    ),
    'locked' => 0,
    'module' => 'blockreference',
    'settings' => array(
      'referenceable_modules' => array(
        'bean' => 'bean',
        'block' => 0,
        'calendar' => 0,
        'comment' => 0,
        'context_ui' => 0,
        'devel' => 0,
        'idap_efq_carousel' => 0,
        'idap_efq_related_content' => 0,
        'idap_footer_links' => 0,
        'idap_page_builder' => 0,
        'idap_subscription_links' => 0,
        'menu' => 0,
        'menu_block' => 0,
        'node' => 0,
        'og_extras' => 0,
        'profile' => 0,
        'search' => 0,
        'shortcut' => 0,
        'statistics' => 0,
        'subscriptions_ui' => 0,
        'system' => 0,
        'user' => 0,
        'views' => 0,
      ),
      'referenceable_operator' => 'OR',
      'referenceable_regions' => array(
        '' => 0,
        'content' => 0,
        'dashboard_inactive' => 0,
        'dashboard_main' => 0,
        'dashboard_sidebar' => 0,
        'devel' => 0,
        'footer' => 0,
        'header' => 0,
        'help' => 0,
        'main_menu' => 0,
        'masthead' => 0,
        'page_top' => 0,
        'search' => 0,
        'sidebar_first' => 0,
        'sidebar_second' => 0,
        'top' => 0,
      ),
      'referenceable_theme' => 'default',
      'respect_visibility' => 0,
    ),
    'translatable' => 0,
    'type' => 'blockreference',
  );

  // Exported field_base: 'field_block_2'
  $field_bases['field_block_2'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_block_2',
    'foreign keys' => array(
      'bid' => array(
        'columns' => array(
          'bid' => 'bid',
        ),
        'table' => 'block',
      ),
    ),
    'indexes' => array(
      'bid' => array(
        0 => 'bid',
      ),
    ),
    'locked' => 0,
    'module' => 'blockreference',
    'settings' => array(
      'referenceable_modules' => array(
        'bean' => 'bean',
        'block' => 0,
        'calendar' => 0,
        'comment' => 0,
        'context_ui' => 0,
        'devel' => 0,
        'idap_efq_carousel' => 0,
        'idap_efq_related_content' => 0,
        'idap_footer_links' => 0,
        'idap_page_builder' => 0,
        'idap_subscription_links' => 0,
        'menu' => 0,
        'menu_block' => 0,
        'node' => 0,
        'og_extras' => 0,
        'profile' => 0,
        'search' => 0,
        'shortcut' => 0,
        'statistics' => 0,
        'subscriptions_ui' => 0,
        'system' => 0,
        'user' => 0,
        'views' => 0,
      ),
      'referenceable_operator' => 'OR',
      'referenceable_regions' => array(
        '' => 0,
        'content' => 0,
        'dashboard_inactive' => 0,
        'dashboard_main' => 0,
        'dashboard_sidebar' => 0,
        'devel' => 0,
        'footer' => 0,
        'header' => 0,
        'help' => 0,
        'main_menu' => 0,
        'masthead' => 0,
        'page_top' => 0,
        'search' => 0,
        'sidebar_first' => 0,
        'sidebar_second' => 0,
        'top' => 0,
      ),
      'referenceable_theme' => 'default',
      'respect_visibility' => 0,
    ),
    'translatable' => 0,
    'type' => 'blockreference',
  );

  // Exported field_base: 'field_block_3'
  $field_bases['field_block_3'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_block_3',
    'foreign keys' => array(
      'bid' => array(
        'columns' => array(
          'bid' => 'bid',
        ),
        'table' => 'block',
      ),
    ),
    'indexes' => array(
      'bid' => array(
        0 => 'bid',
      ),
    ),
    'locked' => 0,
    'module' => 'blockreference',
    'settings' => array(
      'referenceable_modules' => array(
        'bean' => 'bean',
        'block' => 0,
        'calendar' => 0,
        'comment' => 0,
        'context_ui' => 0,
        'devel' => 0,
        'idap_efq_carousel' => 0,
        'idap_efq_related_content' => 0,
        'idap_footer_links' => 0,
        'idap_page_builder' => 0,
        'idap_subscription_links' => 0,
        'menu' => 0,
        'menu_block' => 0,
        'node' => 0,
        'og_extras' => 0,
        'profile' => 0,
        'search' => 0,
        'shortcut' => 0,
        'statistics' => 0,
        'subscriptions_ui' => 0,
        'system' => 0,
        'user' => 0,
        'views' => 0,
      ),
      'referenceable_operator' => 'OR',
      'referenceable_regions' => array(
        '' => 0,
        'content' => 0,
        'dashboard_inactive' => 0,
        'dashboard_main' => 0,
        'dashboard_sidebar' => 0,
        'devel' => 0,
        'footer' => 0,
        'header' => 0,
        'help' => 0,
        'main_menu' => 0,
        'masthead' => 0,
        'page_top' => 0,
        'search' => 0,
        'sidebar_first' => 0,
        'sidebar_second' => 0,
        'top' => 0,
      ),
      'referenceable_theme' => 'default',
      'respect_visibility' => 0,
    ),
    'translatable' => 0,
    'type' => 'blockreference',
  );

  // Exported field_base: 'field_block_4'
  $field_bases['field_block_4'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_block_4',
    'foreign keys' => array(
      'bid' => array(
        'columns' => array(
          'bid' => 'bid',
        ),
        'table' => 'block',
      ),
    ),
    'indexes' => array(
      'bid' => array(
        0 => 'bid',
      ),
    ),
    'locked' => 0,
    'module' => 'blockreference',
    'settings' => array(
      'referenceable_modules' => array(
        'bean' => 'bean',
        'block' => 0,
        'calendar' => 0,
        'comment' => 0,
        'context_ui' => 0,
        'devel' => 0,
        'idap_efq_carousel' => 0,
        'idap_efq_related_content' => 0,
        'idap_footer_links' => 0,
        'idap_page_builder' => 0,
        'idap_subscription_links' => 0,
        'menu' => 0,
        'menu_block' => 0,
        'node' => 0,
        'og_extras' => 0,
        'profile' => 0,
        'search' => 0,
        'shortcut' => 0,
        'statistics' => 0,
        'subscriptions_ui' => 0,
        'system' => 0,
        'user' => 0,
        'views' => 0,
      ),
      'referenceable_operator' => 'OR',
      'referenceable_regions' => array(
        '' => 0,
        'content' => 0,
        'dashboard_inactive' => 0,
        'dashboard_main' => 0,
        'dashboard_sidebar' => 0,
        'devel' => 0,
        'footer' => 0,
        'header' => 0,
        'help' => 0,
        'main_menu' => 0,
        'masthead' => 0,
        'page_top' => 0,
        'search' => 0,
        'sidebar_first' => 0,
        'sidebar_second' => 0,
        'top' => 0,
      ),
      'referenceable_theme' => 'default',
      'respect_visibility' => 0,
    ),
    'translatable' => 0,
    'type' => 'blockreference',
  );

  // Exported field_base: 'field_block_5'
  $field_bases['field_block_5'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_block_5',
    'foreign keys' => array(
      'bid' => array(
        'columns' => array(
          'bid' => 'bid',
        ),
        'table' => 'block',
      ),
    ),
    'indexes' => array(
      'bid' => array(
        0 => 'bid',
      ),
    ),
    'locked' => 0,
    'module' => 'blockreference',
    'settings' => array(
      'referenceable_modules' => array(
        'bean' => 'bean',
        'block' => 0,
        'calendar' => 0,
        'comment' => 0,
        'context_ui' => 0,
        'devel' => 0,
        'idap_efq_carousel' => 0,
        'idap_efq_related_content' => 0,
        'idap_footer_links' => 0,
        'idap_page_builder' => 0,
        'idap_subscription_links' => 0,
        'menu' => 0,
        'menu_block' => 0,
        'node' => 0,
        'og_extras' => 0,
        'profile' => 0,
        'search' => 0,
        'shortcut' => 0,
        'statistics' => 0,
        'subscriptions_ui' => 0,
        'system' => 0,
        'user' => 0,
        'views' => 0,
      ),
      'referenceable_operator' => 'OR',
      'referenceable_regions' => array(
        '' => 0,
        'content' => 0,
        'dashboard_inactive' => 0,
        'dashboard_main' => 0,
        'dashboard_sidebar' => 0,
        'devel' => 0,
        'footer' => 0,
        'header' => 0,
        'help' => 0,
        'main_menu' => 0,
        'masthead' => 0,
        'page_top' => 0,
        'search' => 0,
        'sidebar_first' => 0,
        'sidebar_second' => 0,
        'top' => 0,
      ),
      'referenceable_theme' => 'default',
      'respect_visibility' => 0,
    ),
    'translatable' => 0,
    'type' => 'blockreference',
  );

  // Exported field_base: 'field_block_6'
  $field_bases['field_block_6'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_block_6',
    'foreign keys' => array(
      'bid' => array(
        'columns' => array(
          'bid' => 'bid',
        ),
        'table' => 'block',
      ),
    ),
    'indexes' => array(
      'bid' => array(
        0 => 'bid',
      ),
    ),
    'locked' => 0,
    'module' => 'blockreference',
    'settings' => array(
      'referenceable_modules' => array(
        'bean' => 'bean',
        'block' => 0,
        'calendar' => 0,
        'comment' => 0,
        'context_ui' => 0,
        'devel' => 0,
        'idap_efq_carousel' => 0,
        'idap_efq_related_content' => 0,
        'idap_footer_links' => 0,
        'idap_page_builder' => 0,
        'idap_subscription_links' => 0,
        'menu' => 0,
        'menu_block' => 0,
        'node' => 0,
        'og_extras' => 0,
        'profile' => 0,
        'search' => 0,
        'shortcut' => 0,
        'statistics' => 0,
        'subscriptions_ui' => 0,
        'system' => 0,
        'user' => 0,
        'views' => 0,
      ),
      'referenceable_operator' => 'OR',
      'referenceable_regions' => array(
        '' => 0,
        'content' => 0,
        'dashboard_inactive' => 0,
        'dashboard_main' => 0,
        'dashboard_sidebar' => 0,
        'devel' => 0,
        'footer' => 0,
        'header' => 0,
        'help' => 0,
        'main_menu' => 0,
        'masthead' => 0,
        'page_top' => 0,
        'search' => 0,
        'sidebar_first' => 0,
        'sidebar_second' => 0,
        'top' => 0,
      ),
      'referenceable_theme' => 'default',
      'respect_visibility' => 0,
    ),
    'translatable' => 0,
    'type' => 'blockreference',
  );

  // Exported field_base: 'field_country'
  $field_bases['field_country'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_country',
    'foreign keys' => array(
      'tid' => array(
        'columns' => array(
          'tid' => 'tid',
        ),
        'table' => 'taxonomy_term_data',
      ),
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'countries',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_flag'
  $field_bases['field_flag'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_flag',
    'foreign keys' => array(
      'fid' => array(
        'columns' => array(
          'fid' => 'fid',
        ),
        'table' => 'file_managed',
      ),
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_official_name'
  $field_bases['field_official_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_official_name',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_theme'
  $field_bases['field_theme'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_theme',
    'foreign keys' => array(
      'tid' => array(
        'columns' => array(
          'tid' => 'tid',
        ),
        'table' => 'taxonomy_term_data',
      ),
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'themes',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'group_access'
  $field_bases['group_access'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'group_access',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'no_ui' => TRUE,
    'settings' => array(
      'allowed_values' => array(
        0 => 'Public - accessible to all site users',
        1 => 'Private - accessible only to group members',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'group_content_access'
  $field_bases['group_content_access'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'group_content_access',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'no_ui' => TRUE,
    'settings' => array(
      'allowed_values' => array(
        0 => 'Use group defaults',
        1 => 'Public - accessible to all site users',
        2 => 'Private - accessible only to group members',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  // Exported field_base: 'group_group'
  $field_bases['group_group'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'group_group',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'Not a group',
        1 => 'Group',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'og_roles_permissions'
  $field_bases['og_roles_permissions'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'og_roles_permissions',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'Use default roles and permissions',
        1 => 'Override default roles and permissions',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  return $field_bases;
}
