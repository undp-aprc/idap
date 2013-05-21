<?php
/**
 * @file
 * node_types.features.inc
 */

/**
 * Implements hook_node_info().
 */
function node_types_node_info() {
  $items = array(
    'blog' => array(
      'name' => t('Blog'),
      'base' => 'node_content',
      'description' => t('Reflective and analytical articles written by members of the community.'),
      'has_title' => '1',
      'title_label' => t('Article Title'),
      'help' => '',
    ),
    'carousel' => array(
      'name' => t('Carousel'),
      'base' => 'node_content',
      'description' => t('Create items for the highlight carousel (Eg. used on the home page).'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
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
    'content_landing_page_type_5' => array(
      'name' => t('Content Landing Page - Type 5'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'country_activity' => array(
      'name' => t('Country Activity'),
      'base' => 'node_content',
      'description' => t('Add an entry in the Country Initiatives Database'),
      'has_title' => '1',
      'title_label' => t('Name of this activity'),
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
    'group_collaboration' => array(
      'name' => t('Collaboration Space'),
      'base' => 'node_content',
      'description' => t('Create a space where group members can share content. The space may be either open to the public or closed and accessible to members only. You can control who has access to the space.'),
      'has_title' => '1',
      'title_label' => t('Collaboration Space Name'),
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
