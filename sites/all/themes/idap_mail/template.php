<?php
/* Preprocess function for theme_page() */
function idap_mail_preprocess_page(&$page) {
	
	
	// Custom settings for all pages
	$page['logo'] = idap_mail_helper_construct_image_link('/images/logos/logo.png', '<front>', 'Inclusive Development Asia-Pacific'); //Change the default logo
	$page['undp_logo'] = idap_mail_helper_construct_image_link('/images/logos/undp.png', 'http://www.undp.org', 'UNDP: Empowered Lives, Resilient Nations', '_blank');
	
	//Social Media Icons	
	$page['social_media_icons']['facebook'] = idap_mail_helper_construct_image_link('/images/icons/facebook.png', 'http://www.facebook.com', 'Facebook', '_blank');
	$page['social_media_icons']['twitter'] = idap_mail_helper_construct_image_link('/images/icons/twitter.png', 'http://www.twitter.com', 'Twitter', '_blank');
	$page['social_media_icons']['youtube'] = idap_mail_helper_construct_image_link('/images/icons/youtube.png', 'http://www.youtube.com', 'Youtube', '_blank');
}

/* Theme the footer menu */
function idap_mail_menu_tree__menu_footer_menu($variables) {
	 return '<ul class="horizontal-menu">' . $variables['tree'] . '</ul>';
}

/***
/***
/*** Helper functions ***/

/* Construct image links */
function idap_mail_helper_construct_image_link($path, $href, $alt, $target = NULL) {
		$icon = theme('image', array('path' => path_to_theme().$path, 'alt' => t($alt)));
		$link = theme('link', array('path'=>$href,'text'=>$icon, 'options'=>array('attributes'=>array('target'=>$target),'html'=>'true')));
		
		return $link;
}

?>