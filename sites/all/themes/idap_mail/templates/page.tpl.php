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
* least, this will always default to /.
* - $directory: The directory the template is located in, e.g. modules/system
* or themes/bartik.
* - $is_front: TRUE if the current page is the front page.
* - $logged_in: TRUE if the user is registered and signed in.
* - $is_admin: TRUE if the user has permission to access administration pages.
*
* Site identity:
* - $front_page: The URL of the front page. Use this instead of $base_path,
* when linking to the front page. This includes the language domain or
* prefix.
* - $logo: The path to the logo image, as defined in theme configuration.
* - $site_name: The name of the site, empty when display has been disabled
* in theme settings.
* - $site_slogan: The slogan of the site, empty when display has been disabled
* in theme settings.
* - $hide_site_name: TRUE if the site name has been toggled off on the theme
* settings page. If hidden, the "element-invisible" class is added to make
* the site name visually hidden, but still accessible.
* - $hide_site_slogan: TRUE if the site slogan has been toggled off on the
* theme settings page. If hidden, the "element-invisible" class is added to
* make the site slogan visually hidden, but still accessible.
*
* Navigation:
* - $main_menu (array): An array containing the Main menu links for the
* site, if they have been configured.
* - $secondary_menu (array): An array containing the Secondary menu links for
* the site, if they have been configured.
* - $breadcrumb: The breadcrumb trail for the current page.
*
* Page content (in order of occurrence in the default page.tpl.php):
* - $title_prefix (array): An array containing additional output populated by
* modules, intended to be displayed in front of the main title tag that
* appears in the template.
* - $title: The page title, for use in the actual HTML content.
* - $title_suffix (array): An array containing additional output populated by
* modules, intended to be displayed after the main title tag that appears in
* the template.
* - $messages: HTML for status and error messages. Should be displayed
* prominently.
* - $tabs (array): Tabs linking to any sub-pages beneath the current page
* (e.g., the view and edit tabs when displaying a node).
* - $action_links (array): Actions local to the page, such as 'Add menu' on the
* menu administration interface.
* - $feed_icons: A string of all feed icons for the current page.
* - $node: The node object, if there is an automatically-loaded node
* associated with the page, and the node ID is the second argument
* in the page's path (e.g. node/12345 and node/12345/revisions, but not
* comment/reply/12345).
*
*
* @see template_preprocess()
* @see template_preprocess_page()
* @see template_process()
* @see bartik_process_page()
* @see html.tpl.php
*/
?>
<style>
	td {
		padding:10px;
	}
	p {
		margin-bottom:10px;
	}
</style>
<!-- Beginning page.tpl.php template -->
<table width="750" border="0" align="center" cellpadding="10" cellspacing="0" style="background-color:#ffffff;margin:0 auto 0 auto;padding:10px;margin-bottom:20px;">
<tr>
<td width="77" rowspan="2"><a href="http://www.undp.org" target="_blank"><img src="http://idap:8888/sites/all/themes/idap/images/logos/undp.png" alt="UNDP Logo" style="border:0px;"/></a></td>
<td width="25"><a href="http://www.youtube.com" target="_blank"><img src="http://idap:8888/sites/all/themes/idap/images/icons/youtube.png" alt="Youtube" border="0" /></a></td>
<td width="25"><a href="http://www.facebook.com" target="_blank"><img src="http://idap:8888/sites/all/themes/idap/images/icons/facebook.png" alt="Facebook" border="0" /></a></td>
<td width="25" valign="top"><a href="http://www.twitter.com" target="_blank"><img src="http://idap:8888/sites/all/themes/idap/images/icons/twitter.png" alt="Twitter" border="0" /></a></td>
<td width="367" valign="top" colspan="4"></td>
</tr>
<tr>
<td colspan="7" valign="top"><a href="http://www.inclusivedevelopmentasiapacific.net" target="_blank"><img src="http://idap:8888/sites/all/themes/idap/images/logos/logo.png" alt="Site Logo" border="0" /></a></td>
</tr>
<tr><td colspan="8">
<div style="margin-top:10px;padding-top:10px;border-top:1px solid #cccccc;"></div>
<?php if ($page['content']): ?>
<?php print render($page['content']); ?>
<?php endif; ?>
</td></tr>
<tr style="background-color:#EEBC5F;">
  	<td width="430" colspan="4" style="font-size:0.7em;">&copy; United Nations Development Programme 2012</td>
    <td width="80"><a title="About Inclusive Development Asia-Pacific" href="http://www.inclusivedevelopmentasiapacific.net/about" style="text-decoration:none;color:#000;font-size:0.7em;">About Us</a></td>
    <td width="80"><a title="Contact us using our contact form or through other contact methods." href="http://www.inclusivedevelopmentasiapacific.net/contact" style="text-decoration:none;color:#000;font-size:0.7em;">Contact</a></td>
    <td width="80"><a title="Information about the privacy policy that governs how IDAP may use personal information collected through this site." href="http://www.inclusivedevelopmentasiapacific.net/privacy" style="text-decoration:none;color:#000;font-size:0.7em;">Privacy Statement</a></td>
    <td width="80"><a title="Terms and Conditions for membership, content creation and sharing." href="http://www.inclusivedevelopmentasiapacific.net/terms" style="text-decoration:none;color:#000;font-size:0.7em;">Terms &amp; Conditions</a></td>
  </tr>
  <tr style="background-color:#EAEAEB"><td colspan="8">
  <address style="font-style:normal;font-size:0.7em">
  <b>The United Nations Development Programme (Asia Pacific Regional Center)</b>
  </address>
  <address style="font-style:normal;font-size:0.7em">
  Level 3 UN Service Building
  </address>
  <address style="font-style:normal;font-size:0.7em">
  Ratchadamnoen Nok Avenue
  </address>
  <address style="font-style:normal;font-size:0.7em">
  Bangkok 10300 Thailand
  </address>
  </td></tr>
</table>