<?php
/**
 * @file
 * Bartik's theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template normally located in the
 * modules/system directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 * - $hide_site_name: TRUE if the site name has been toggled off on the theme
 *   settings page. If hidden, the "element-invisible" class is added to make
 *   the site name visually hidden, but still accessible.
 * - $hide_site_slogan: TRUE if the site slogan has been toggled off on the
 *   theme settings page. If hidden, the "element-invisible" class is added to
 *   make the site slogan visually hidden, but still accessible.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see bartik_process_page()
 * @see html.tpl.php
 */
?>
<!-- Beginning page.tpl.php template -->
<div id="top">
	<?php if($page['top']): ?>
		<?php print render($page['top']); ?>
	<?php endif; ?>
	<div class="clearfix"></div>
</div>
<div id="page">
	<div class="enclosure page">
		<div id="header">
			<div class="enclosure header">
				<div id="header-navigation">
					<div class="enclosure header-navigation">
						<div class="container logo undp">
							<?php print $undp_logo; ?>
						</div> <!-- .container .logo .undp -->
						<div class="container logo site-logo">
							<?php print $logo; ?>
						</div> <!-- .container .logo .site-logo -->
						<div id="utilities">
							<div class="container utilities">
								<div class="social-media-icons container-inline">
									<div><?php print $social_media_icons['facebook']; ?></div>
									<div><?php print $social_media_icons['twitter']; ?></div>
									<div class="last"><?php print $social_media_icons['youtube']; ?></div>
									<div class="clearfix"></div>
								</div> <!-- .social-media-icon -->
								<div class="block block-search" id="block-search-form">
									<?php if ($page['search']): ?>
										<?php print render($page['search']); ?>
									<?php endif; ?>
									<div class="clearfix"></div>
								</div>
							</div> <!-- .container utilities -->
						</div><!-- #utilities -->
						<div id="main-menu">
							<?php if ($main_menu): ?>
								<?php print theme('links__system_main_menu', array('links' => $main_menu, 'attributes' => array('class' => array('menu')))); ?>
							<?php endif; ?>
							<div class="clearfix"></div>
						</div> <!-- #main-menu -->
						<div class="clearfix"></div>
					</div> <!-- .enclosure .header-navigation -->
				</div> <!-- #header-navigation -->
			</div> <!-- .enclosure .header -->
		</div> <!-- #header -->
		<div id="main">
			<div class="enclosure main">
				<?php if ($page['masthead']): ?>
					<?php print render($page['masthead']); ?>
				<?php endif; ?>
				<?php if ($breadcrumb): ?>
					<?php print $breadcrumb; ?>
				<?php endif; ?>
				<?php if ($messages): ?>
					<?php print($messages); ?>
				<?php endif; ?>
				<?php if($is_admin): //Only show tabs for administrator users ?>
					<?php if($tabs): ?>
						<?php print render($tabs); ?>
					<?php endif; ?>
				<?php endif; ?>
				<?php if ($page['sidebar_first']): ?>
					<div class="sidebar" id="sidebar-left">
						<div class="enclosure">
							<?php print render($page['sidebar_first']); ?>
						</div> <!-- .enclosure -->
					</div>
				<?php endif; ?>
				<div id="content">
					<div class="enclosure">
					<?php if($title): ?>
						<h1><?php print $title; ?></h1>
					<?php endif; ?>
					<?php if ($page['content']): ?>
						<?php print render($page['content']); ?>
					<?php endif; ?>
					</div> <!-- .enclosure -->
				</div> <!-- #content -->
				<?php if ($page['sidebar_second']): ?>
					<div class="sidebar" id="sidebar-right">
						<div class="enclosure">
							<?php print render($page['sidebar_second']); ?>
						</div> <!-- .enclosure -->
					</div>
				<?php endif; ?>
				<div class="clearfix"></div>
			</div> <!-- .enclosure .main -->
		</div> <!-- #main -->
		<div id="footer">
			<div class="enclosure footer">
				<?php if($page['footer']): ?>
					<?php print render($page['footer']); ?>
				<?php endif; ?>
				<div class="clearfix"></div>
			</div> <!-- .enclosure .footer -->
		</div> <!-- #footer -->
	</div> <!-- .enclosure .page -->
</div> <!-- #page -->
<?php if ($page['devel']): ?>
<div id="devel">
		<?php print render($page['devel']); ?>
</div>
<?php endif; ?>
<!-- End page.tpl.php -->