<?php
/**
 * @file
 * node_types.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function node_types_field_default_field_bases() {
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

  // Exported field_base: 'event_contact_details'
  $field_bases['event_contact_details'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'event_contact_details',
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
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'event_participation'
  $field_bases['event_participation'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'event_participation',
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
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'event_type'
  $field_bases['event_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'event_type',
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
        'Conference' => 'Conference',
        'Training of Trainers' => 'Training of Trainers',
        'Workshop' => 'Workshop',
        'Other' => 'Other',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_activity_scope'
  $field_bases['field_activity_scope'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_activity_scope',
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
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_activity_timeline'
  $field_bases['field_activity_timeline'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_activity_timeline',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'date',
    'settings' => array(
      'cache_count' => 4,
      'cache_enabled' => 1,
      'granularity' => array(
        'day' => 0,
        'hour' => 0,
        'minute' => 0,
        'month' => 'month',
        'second' => 0,
        'year' => 'year',
      ),
      'timezone_db' => '',
      'todate' => 'optional',
      'tz_handling' => 'none',
    ),
    'translatable' => 0,
    'type' => 'datetime',
  );

  // Exported field_base: 'field_application_instructions'
  $field_bases['field_application_instructions'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_application_instructions',
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
    'translatable' => 0,
    'type' => 'text_long',
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

  // Exported field_base: 'field_block_7'
  $field_bases['field_block_7'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_block_7',
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
        'idap_og_blocks' => 0,
        'idap_page_builder' => 0,
        'menu' => 0,
        'menu_block' => 0,
        'node' => 0,
        'profile' => 0,
        'search' => 0,
        'shortcut' => 0,
        'statistics' => 0,
        'subscriptions_ui' => 0,
        'system' => 0,
        'unsubscribe_feedback' => 0,
        'user' => 0,
        'views' => 0,
      ),
      'referenceable_operator' => 'AND',
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
        'overlay' => 0,
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

  // Exported field_base: 'field_block_8'
  $field_bases['field_block_8'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_block_8',
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
        'idap_og_blocks' => 0,
        'idap_page_builder' => 0,
        'menu' => 0,
        'menu_block' => 0,
        'node' => 0,
        'profile' => 0,
        'search' => 0,
        'shortcut' => 0,
        'statistics' => 0,
        'subscriptions_ui' => 0,
        'system' => 0,
        'unsubscribe_feedback' => 0,
        'user' => 0,
        'views' => 0,
      ),
      'referenceable_operator' => 'AND',
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
        'overlay' => 0,
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

  // Exported field_base: 'field_carousel_image'
  $field_bases['field_carousel_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_carousel_image',
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

  // Exported field_base: 'field_contact_details'
  $field_bases['field_contact_details'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_contact_details',
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
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_coordinating_agency'
  $field_bases['field_coordinating_agency'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_coordinating_agency',
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
          'vocabulary' => 'agency',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
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

  // Exported field_base: 'field_date'
  $field_bases['field_date'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_date',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'date',
    'settings' => array(
      'cache_count' => 4,
      'cache_enabled' => 0,
      'granularity' => array(
        'day' => 'day',
        'hour' => 0,
        'minute' => 0,
        'month' => 'month',
        'second' => 0,
        'year' => 'year',
      ),
      'repeat' => 0,
      'timezone_db' => '',
      'todate' => 'optional',
      'tz_handling' => 'none',
    ),
    'translatable' => 0,
    'type' => 'datetime',
  );

  // Exported field_base: 'field_e_discussion_resources'
  $field_bases['field_e_discussion_resources'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_e_discussion_resources',
    'foreign keys' => array(
      'node' => array(
        'columns' => array(
          'target_id' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'direction' => 'ASC',
          'field' => 'body:value',
          'property' => 'nid',
          'type' => 'none',
        ),
        'target_bundles' => array(
          'resource' => 'resource',
        ),
      ),
      'handler_submit' => 'Change handler',
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_expected_results'
  $field_bases['field_expected_results'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_expected_results',
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
    'translatable' => 0,
    'type' => 'text_with_summary',
  );

  // Exported field_base: 'field_linked_collaboration_space'
  $field_bases['field_linked_collaboration_space'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_linked_collaboration_space',
    'foreign keys' => array(
      'node' => array(
        'columns' => array(
          'target_id' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'group_collaboration' => 'group_collaboration',
        ),
      ),
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_news_date'
  $field_bases['field_news_date'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_news_date',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'date',
    'settings' => array(
      'cache_count' => 4,
      'cache_enabled' => 1,
      'granularity' => array(
        'day' => 'day',
        'hour' => 0,
        'minute' => 0,
        'month' => 'month',
        'second' => 0,
        'year' => 'year',
      ),
      'timezone_db' => '',
      'todate' => '',
      'tz_handling' => 'none',
    ),
    'translatable' => 0,
    'type' => 'datetime',
  );

  // Exported field_base: 'field_opportunity_closing_date'
  $field_bases['field_opportunity_closing_date'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_opportunity_closing_date',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'date',
    'settings' => array(
      'cache_count' => 4,
      'cache_enabled' => 0,
      'granularity' => array(
        'day' => 'day',
        'hour' => 0,
        'minute' => 0,
        'month' => 'month',
        'second' => 0,
        'year' => 'year',
      ),
      'timezone_db' => '',
      'todate' => '',
      'tz_handling' => 'none',
    ),
    'translatable' => 0,
    'type' => 'datetime',
  );

  // Exported field_base: 'field_opportunity_type'
  $field_bases['field_opportunity_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_opportunity_type',
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
        'Contract' => 'Contract',
        'Grant' => 'Grant',
        'Job' => 'Job',
        'Fellowship' => 'Fellowship',
        'Scholarship' => 'Scholarship',
        'Public Tender' => 'Public Tender',
        'Volunteer/Pro Bono' => 'Volunteer/Pro Bono',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_partners'
  $field_bases['field_partners'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_partners',
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
          'vocabulary' => 'agency',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_photo'
  $field_bases['field_photo'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_photo',
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

  // Exported field_base: 'field_publication_date'
  $field_bases['field_publication_date'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_publication_date',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'date',
    'settings' => array(
      'cache_count' => 4,
      'cache_enabled' => 1,
      'granularity' => array(
        'day' => 'day',
        'hour' => 0,
        'minute' => 0,
        'month' => 'month',
        'second' => 0,
        'year' => 'year',
      ),
      'timezone_db' => '',
      'todate' => '',
      'tz_handling' => 'none',
    ),
    'translatable' => 0,
    'type' => 'datetime',
  );

  // Exported field_base: 'field_publication_name'
  $field_bases['field_publication_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_publication_name',
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

  // Exported field_base: 'field_read_more_link'
  $field_bases['field_read_more_link'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_read_more_link',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_regions'
  $field_bases['field_regions'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_regions',
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
        'south_asia' => 'South Asia',
        'west_asia' => 'West Asia',
        'north_east_asia' => 'North East Asia',
        'mekong' => 'Mekong',
        'asia_pacific' => 'Whole Asia-Pacific Region',
        'south_east_asia' => 'South East Asia',
        'pacific' => 'Pacific',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_related_files'
  $field_bases['field_related_files'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_related_files',
    'foreign keys' => array(
      'node' => array(
        'columns' => array(
          'target_id' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'direction' => 'ASC',
          'field' => 'body:value',
          'property' => 'nid',
          'type' => 'none',
        ),
        'target_bundles' => array(
          'resource' => 'resource',
        ),
      ),
      'handler_submit' => 'Change handler',
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_resource_file'
  $field_bases['field_resource_file'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_resource_file',
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
    'module' => 'file',
    'settings' => array(
      'display_default' => 0,
      'display_field' => 0,
      'uri_scheme' => 'private',
    ),
    'translatable' => 0,
    'type' => 'file',
  );

  // Exported field_base: 'field_resource_type'
  $field_bases['field_resource_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_resource_type',
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
        'Manual' => 'Manual',
        'Policy Paper' => 'Policy Paper',
        'Report' => 'Report',
        'Toolkit' => 'Toolkit',
        'Training Materials' => 'Training Materials',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_resource_url'
  $field_bases['field_resource_url'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_resource_url',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_source_url'
  $field_bases['field_source_url'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_source_url',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
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

  // Exported field_base: 'og_group_ref'
  $field_bases['og_group_ref'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'og_group_ref',
    'foreign keys' => array(
      'node' => array(
        'columns' => array(
          'target_id' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'og',
      'handler_settings' => array(
        'behaviors' => array(
          'og_behavior' => array(
            'status' => TRUE,
          ),
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'membership_type' => 'og_membership_type_default',
        'sort' => array(
          'direction' => 'ASC',
          'field' => 'body:value',
          'property' => 'nid',
          'type' => 'none',
        ),
        'target_bundles' => array(
          'group_collaboration' => 'group_collaboration',
        ),
      ),
      'handler_submit' => 'Change handler',
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
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
