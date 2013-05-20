<?php
/**
 * @file
 * idap_feature_article_content_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function idap_feature_article_content_types_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function idap_feature_article_content_types_node_info() {
  $items = array(
    'blog' => array(
      'name' => t('Blog'),
      'base' => 'node_content',
      'description' => t('Reflective and analytical articles written by members of the community.'),
      'has_title' => '1',
      'title_label' => t('Article Title'),
      'help' => '',
    ),
    'e_discussion' => array(
      'name' => t('E-Discussion'),
      'base' => 'node_content',
      'description' => t('Create E-Discussions '),
      'has_title' => '1',
      'title_label' => t('E-Discussion Title'),
      'help' => '',
    ),
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('Events are upcoming activities, such as workshops, conferences or meetings that you would like to inform Inclusive Development members about.'),
      'has_title' => '1',
      'title_label' => t('Event Name'),
      'help' => '',
    ),
    'media_article' => array(
      'name' => t('Media Article'),
      'base' => 'node_content',
      'description' => t('Share articles, such as news and opinion pieces, that have been published in the media.'),
      'has_title' => '1',
      'title_label' => t('Headline'),
      'help' => '',
    ),
    'network_news' => array(
      'name' => t('Network News'),
      'base' => 'node_content',
      'description' => t('News items from the network. If you wish to share published news articles, please use the <em>media articles</em> content type.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'opportunities' => array(
      'name' => t('Jobs and Opportunities'),
      'base' => 'node_content',
      'description' => t('A listing of jobs and other opportunities, such as grants, fellowships and pro bono service opportunities.'),
      'has_title' => '1',
      'title_label' => t('Job Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Page Title'),
      'help' => '',
    ),
    'regional_initiative' => array(
      'name' => t('Regional Initiative'),
      'base' => 'node_content',
      'description' => t('Post information about regional initiatives in each of the thematic areas.'),
      'has_title' => '1',
      'title_label' => t('Regional Initiative Title'),
      'help' => '',
    ),
    'resource' => array(
      'name' => t('Resource'),
      'base' => 'node_content',
      'description' => t('Add items, such as publications, reports, manuals and toolkits, the resource library.'),
      'has_title' => '1',
      'title_label' => t('Resource Title'),
      'help' => '',
    ),
  );
  return $items;
}
