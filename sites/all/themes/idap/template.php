<?php
function idap_theme($existing, $type, $theme, $path) {
	$items['comma_list'] = array(
		'render element' => 'element',
		'variables' => array(
			'element' => array(
				'list_items' => NULL,
			),
		),
	);
	$items['vertical_table'] = array(
		'render element' => 'element',
		'variables' => array(
			'element' => array(
				'data' => NULL,
			),
		),
	);
	$items['idap_main_menu'] = array(
		'render element' => 'element',
		'template' => 'idap-main-menu',
		'path' => drupal_get_path('theme','idap').'/templates/system-templates',
	);
	$items['idap_secondary_menu'] = array(
		'render element' => 'element',
		'template' => 'idap-secondary-menu',
		'path' => drupal_get_path('theme','idap').'/templates/system-templates',
	);
	return $items;
}

function idap_comma_list($variables) {
	$contents = '';
	$list_items = $variables['items'];
	$item_qty = count($list_items);
	
	foreach ($list_items as $delta=>$item) {
		$next_item = $delta+1;
		
		if (!empty($list_items[$next_item])) {
			$contents .= "<span>$item</span>, ";
		} else {
			$contents .= "<span>$item</span>";
		}
	}
	
	$output = '<div class="comma-list">'.$contents.'</div>';
	return $output;
};

/* Preprocess function for theme_page() */
function idap_preprocess_page(&$page) {
	global $user;

	// Custom settings for the front page
	if ($page['is_front']) {
		drupal_add_css(path_to_theme().'/css/page--front.css');
		hide($page['page']['content']['system_main']); // Don't show default content on home page
	}
	
	// Custom settings for all pages
	$page['logo'] = idap_helper_construct_image_link('/images/logos/logo.png', '<front>', 'Inclusive Development Asia-Pacific'); //Change the default logo
	$page['undp_logo'] = idap_helper_construct_image_link('/images/logos/undp.png', 'http://www.undp.org', 'UNDP: Empowered Lives, Resilient Nations', '_blank');
	
	//Social Media Icons	
	$page['social_media_icons']['facebook'] = idap_helper_construct_image_link('/images/icons/facebook.png', 'http://www.facebook.com', 'Facebook', '_blank');
	$page['social_media_icons']['twitter'] = idap_helper_construct_image_link('/images/icons/twitter.png', 'http://www.twitter.com', 'Twitter', '_blank');
	$page['social_media_icons']['youtube'] = idap_helper_construct_image_link('/images/icons/youtube.png', 'http://www.youtube.com', 'Youtube', '_blank');
	
	//Add hook theme suggestions for pages with different node types
	if (isset($page['node']->type)) {
		$page['theme_hook_suggestions'][] = 'page__node__'.$page['node']->type;
	}
	
	//Create renderable array of front page node (assigned in admin/config/system/site-information) to $page['home_page_node]
	if(isset($page['page']['content']['system_main']['nodes']) && $page['is_front']) {
		$nodes = $page['page']['content']['system_main']['nodes'];
		foreach($nodes as $delta=>$value) {
			if(is_integer($delta)) {
				$page['page']['home_page_node'][$delta] = $nodes[$delta];
			}
		}
	}
	
	//Remove the theme_hook_suggestion for page--node--thematic-home-page-type-2.tpl.php if viewing front page because it takes precedence over page--front.tpl.php
	if($page['is_front']) {
		foreach($page['theme_hook_suggestions'] as $delta=>$value) {
			if (fnmatch('page__node__content_landing_page_type_*',$value)) {
				unset($page['theme_hook_suggestions'][$delta]);
			}
		}
	}
	
	//Consider 'Content Manager' role to be admin too
	foreach ($user->roles as $delta=>$role) {
		if ($role == 'Content Manager') {
			$page['is_admin'] = TRUE;
		}
	}
}

/* Preprocess function for node.tpl.php */
function idap_preprocess_node(&$variables) {
	$node_type = $variables['type'];
	$view_mode = $variables['view_mode'];
	
	switch($node_type) {
		case 'network_news':
			drupal_add_css(path_to_theme().'/css/nodes/network-news.css');
			if ($variables['view_mode'] == 'full') {
				$variables['theme_hook_suggestions'][] = 'node__network_news__full';
				
				$variables['region_photo'] = array();
				$variables['region_main'] = array();
				
				$variables['region_photo'][] = $variables['content']['group_photo_container'];
				hide($variables['content']['group_photo_container']);
			}
		break;
		case 'country_activity':
			drupal_add_css(path_to_theme().'/css/nodes/country-activity.css');
			if ($variables['view_mode'] == 'full') {
				$variables['theme_hook_suggestions'][] = 'node__country_activity__full';
				
				$variables['content']['vertical_table'] = theme('vertical_table',array('element'=>array('data' => $variables['content'])));
			}
		break;
		case 'blog':
			drupal_add_css(path_to_theme().'/css/nodes/blog.css');
			if ($variables['view_mode'] == 'full') {
				$variables['theme_hook_suggestions'][] = 'node__blog__full';
				
				$variables['region_metadata'] = array();
				
				$variables['region_metadata'][] = $variables['content']['field_theme'];
				hide($variables['content']['field_theme']);
				
				if (isset($variables['content']['og_group_ref'])) {
					$variables['region_metadata'][] = $variables['content']['og_group_ref'];
					hide($variables['content']['og_group_ref']);
				}
			}
		break;
		case 'resource':
			drupal_add_css(path_to_theme().'/css/nodes/resource.css');
			if ($variables['view_mode'] == 'full') {
				$variables['theme_hook_suggestions'][] = 'node__resource__full';
				
				$variables['region_metadata'] = array();
				
				$variables['region_metadata'][] = $variables['content']['field_resource_type'];
				hide($variables['content']['field_resource_type']);
				
				$variables['region_metadata'][] = $variables['content']['field_resource_url'];
				hide($variables['content']['field_resource_url']);
				
				$variables['region_metadata'][] = $variables['content']['field_resource_file'];
				hide($variables['content']['field_resource_file']);
				
				$variables['region_metadata'][] = $variables['content']['field_theme'];
				hide($variables['content']['field_theme']);
				
				if (isset($variables['content']['og_group_ref'])) {
					$variables['region_metadata'][] = $variables['content']['og_group_ref'];
					hide($variables['content']['og_group_ref']);
				}
			}
		break;
	}
	
	/* Special settings for custom view modes */
	switch($view_mode) {
		case 'teaser_bullets':
			unset($variables['content']['title']['#prefix']);
			unset($variables['content']['title']['#suffix']);
			break;
		case 'title_bullets':
			unset($variables['content']['title']['#prefix']);
			unset($variables['content']['title']['#suffix']);
			break;
		case 'teaser':
			unset($variables['content']['title']['#prefix']);
			unset($variables['content']['title']['#suffix']);
			break;
		case 'photo_teaser':
			unset($variables['content']['title']['#prefix']);
			unset($variables['content']['title']['#suffix']);
		case 'title_only':
				unset($variables['content']['title']['#prefix']);
				unset($variables['content']['title']['#suffix']);
		break;
	}
}

function preprocess_node__idap_bean__teaser_bullets(&$variables) {
	
}

/* Preprocess functino for theme_vertical_table */
function idap_preprocess_vertical_table(&$variables) {
	$data = $variables['element']['data'];
	$row = array();
	if (isset($data['field_country'])) {
		$row['field_country'] = array(
			'title'=>t('Country(s):'),
			'data'=>$data['field_country'],
		); 
	};
	if (isset($data['field_regions'])) {
		$row['field_regions'] = array(
			'title'=>t('Region(s):'),
			'data'=>$data['field_regions'],
		); 
	};
	if (isset($data['field_expected_results'])) {
		$row['field_expected_results'] = array(
			'title'=>t('Expected Results:'),
			'data'=>$data['field_expected_results'],
		); 
	};
	if (isset($data['field_activity_scope'])) {
		$row['field_activity_scope'] = array(
			'title'=>t('Activity Scope:'),
			'data'=>$data['field_activity_scope'],
		); 
	};
	if (isset($data['field_coordinating_agency'])) {
		$row['field_coordinating_agency'] = array(
			'title'=>t('Coordinating Agency(s):'),
			'data'=>$data['field_coordinating_agency'],
		); 
	};
	if (isset($data['field_partners'])) {
		$row['field_partners'] = array(
			'title'=>t('Partner(s):'),
			'data'=>$data['field_partners'],
		); 
	};
	if (isset($data['field_activity_timeline'])) {
		$row['field_activity_timeline'] = array(
			'title'=>t('Activity Timeline:'),
			'data'=>$data['field_activity_timeline'],
		); 
	};
	if (isset($data['field_related_files'])) {
		$row['field_related_files'] = array(
			'title'=>t('Related Files/URLs:'),
			'data'=>$data['field_related_files'],
		); 
	};
	
	$variables['rows'] = $row;
}

/* Theme function: theme_vertical_table */
function idap_vertical_table($variables) {
	$stripe = 'odd';
	$rows = array();
	
	foreach($variables['rows'] as $key=>$row) {
		$rows[$key] = '<tr class="'.$stripe.'"><td class="title">'.$row['title'].'</td><td>'.drupal_render($row['data']).'</td></tr>';
		$stripe == 'odd' ? $stripe = 'even' : $stripe = 'odd';
	}
	 
	$table_rows = implode($rows);
	$output = '<table id="country-activity-table">'.$table_rows.'</table>';
	
	return $output;
}

function idap_preprocess_block(&$variables) {
	$variables['block_content'] = array();
	if(isset($variables['elements']['nodes'])) {
		$variables['block_content']['node_items'] = '';
		$nodes = $variables['elements']['nodes'];
		foreach($nodes as $delta=>$value) {
			if(is_integer($delta)) {
				$variables['block_content']['node_items'] .= render($nodes[$delta]);
			}
		}
	}
	
	if(isset($variables['elements']['bean'])) {
		$variables['block_content']['bean_items'] = array();
		
		$beans = $variables['elements']['bean'];
		foreach($beans as $delta=>$value) {
			if (isset($beans[$delta]['group_photo']['field_photo'])) {
				$photo = $beans[$delta]['group_photo']['field_photo'];
				$variables['block_content']['bean_items']['photo'] = render($photo);
			}
		}
	}
}

/* theme_links__system_main_menu() */
/* Theme the main menu */
function idap_links__system_main_menu($variables) {
	return theme('idap_main_menu');
}

function idap_preprocess_idap_main_menu(&$variables) {
	$menu_tree = menu_tree_all_data('main-menu');
	
	// Remove home link to <front>
	foreach($menu_tree as $item_1=>$array_1) {
		if ($array_1['link']['link_path'] == '<front>') {
			unset($menu_tree[$item_1]);
		}
	}
	
	$variables['element']['menu_tree'] = $menu_tree;
}

function idap_preprocess_idap_secondary_menu(&$variables) {
	$variables['element']['menu_tree'] = menu_tree_all_data('menu-secondary-menu');
}

/*
/* Theme the thematic page sub-menu system */
function idap_menu_tree__menu_block($variables) {
	$output = "<div id='thematic-section-menu-block'>";
	$output .= "<div class='enclosure'>";
	$output .= '<ul class="menu menu-block">' . $variables['tree'] . '</ul>';
	$output .= "<div class='clearfix'></div>";
	$output .= "</div>"; //.enclosure
	$output .= "</div>"; //#thematic-section-menu-block
	return $output;
}

function idap_menu_link__menu_block(array $variables) {
  	$element = $variables['element'];
	  $sub_menu = '';

	  if ($element['#below']) {
	    $sub_menu = drupal_render($element['#below']);
	  }
	  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
	  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/* Theme the footer menu */

function idap_menu_tree__menu_footer_menu($variables) {
	 return '<ul class="horizontal-menu">' . $variables['tree'] . '</ul>';
}

/* Implements hook_form_FORM_ID_alter() */
/* Alter search block form */
function idap_form_search_block_form_alter(&$form, &$form_state, $form_id) {
	$form['search_block_form']['#id'] = 'edit-search-text';
	
	$form['actions']['submit']['#type'] = 'image_button';
	$form['actions']['submit']['#src'] = path_to_theme().'/images/widgets/search.png';
}

/* Override default theme_breadcrumb() */
function idap_breadcrumb($variables) {
	$breadcrumb = $variables['breadcrumb'];

	  if (!empty($breadcrumb)) {
		$breadcrumb[] = "<span class='light-grey'>".drupal_get_title()."</span>";
	    // Provide a navigational heading to give context for breadcrumb links to
	    // screen-reader users. Make the heading invisible with .element-invisible.
	    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';

	    $output .= '<div class="breadcrumb">' . implode(' » ', $breadcrumb) . '</div>';
	    return $output;
	  }
}

/* Theme function for theme_links__comments() */
function idap_links__comment($variables) {
		global $user;
		$html = '';
		if ($user->uid != 0) { //Only display links content for logged in users
			$links = $variables['links'];
			$html = "<ul class='links inline'>";
			foreach($links as $key=>$value) {
				if (isset($links[$key]['query']['token'])) {
					$token = "?token={$links[$key]['query']['token']}";
				} else {
					$token = NULL;
				}
				$html .= "<li />";
				$html .= "<a href='/{$links[$key]['href']}$token'>{$links[$key]['title']}</a>";	
			}
			$html .= "</ul>";
		}
	return $html;
}

/* Preprocess function for theme_username() */
function idap_preprocess_username(&$variables) {
	$uid = $variables['uid'];
	$author = user_load($uid);
	if($author) {
		if(!empty($author->profile_full_name)) {
			$variables['name'] = $author->profile_full_name;
		} else {
			$variables['name'] = $author->name;
		}
	}
}

function idap_preprocess_extra_fields_title(&$variables) {
	if($variables['view_mode'] == 'title_bullets') {
		$variables['theme_hook_suggestions'][] = 'extra_fields_title__no_html';
	}
}

function idap_extra_fields_title__no_html($variables) {
	  $output = '';
	  $node = $variables['node'];
	  $view_mode = $variables['view_mode'];
	  $entity_uri = entity_uri('node', $node);
	  $output .= l($node->title, $entity_uri['path']);
	  return $output;
}

function idap_preprocess_comment_wrapper(&$variables) {
	$variables['comment_wrapper_commment_title'] = t('Comments');
	$variables['comment_wrapper_commment_form_title'] = t('Add a new comment');
	
	if ($variables['node']->type == 'e_discussion') {
		$variables['comment_wrapper_commment_title'] = t('E-Discussion Contributions');
		$variables['comment_wrapper_commment_form_title'] = t('Contribute to this E-Discussion');
	}
}

function idap_field__field_facilitator_notes__comment_node_e_discussion($variables) {
	$output = '';

	  // Render the label, if it's not hidden.
	  if (!$variables['label_hidden']) {
	    $output .= '<span class="field-label"' . $variables['title_attributes'] . '>' . '[' . $variables['label'] . ':&nbsp;</span>';
	  }

	  // Render the items.
	  
	  foreach ($variables['items'] as $delta => $item) {
	    $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
	    $output .= drupal_render($item);
	  }

	  // Render the top-level DIV.
	  $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . ']' .'</div>';

	  return $output;
}

/***
/***
/*** Helper functions ***/

/* Construct image links */
function idap_helper_construct_image_link($path, $href, $alt, $target = NULL) {
		$icon = theme('image', array('path' => path_to_theme().$path, 'alt' => t($alt)));
		$link = theme('link', array('path'=>$href,'text'=>$icon, 'options'=>array('attributes'=>array('target'=>$target),'html'=>'true')));
		
		return $link;
}

?>