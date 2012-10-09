<?php
/**
 * @file
 * article_content_types.features.inc
 */

/**
 * Implements hook_node_info().
 */
function article_content_types_node_info() {
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
