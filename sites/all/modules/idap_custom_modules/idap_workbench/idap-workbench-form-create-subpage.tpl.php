<?php print render($form['page_title']); ?>
<p>Please choose a layout for your page you are creating by clicking on one of the page layout icons below.</p>
<!-- Content Landing Page Type 1 -->
<div class="page-thumbnail-container inactive" id="content_landing_page_type_1">
	<div class="inner">
<?php
print theme('image',array('path'=>drupal_get_path('module','idap_workbench').'/page_thumbnails/content_landing_page_type_1.png','attributes'=>array('class'=>array('page-thumbnail'),'id'=>'content-landing-page-type-1-thumbnail'))); ?>
		<p>A layout with a large, three-column width highlight box. This is recommended in places where you only need to display a few pieces of content.</p> 
	</div>
</div>

<!-- Content Landing Page Type 2 -->
<div class="page-thumbnail-container inactive" id="content_landing_page_type_2">
	<div class="inner">
<?php
print theme('image',array('path'=>drupal_get_path('module','idap_workbench').'/page_thumbnails/content_landing_page_type_2.png','attributes'=>array('class'=>array('page-thumbnail'),'id'=>'content-landing-page-type-1-thumbnail'))); ?>
		<p>Layout with a highlight box that is two columns wide, then two additional columns. Good for sub-pages when you want to highlight content that has attached pictures.</p> 
	</div>
</div>

<!-- Content Landing Page Type 3 -->
<div class="page-thumbnail-container inactive" id="content_landing_page_type_3">
	<div class="inner">
<?php
print theme('image',array('path'=>drupal_get_path('module','idap_workbench').'/page_thumbnails/content_landing_page_type_3.png','attributes'=>array('class'=>array('page-thumbnail'),'id'=>'content-landing-page-type-1-thumbnail'))); ?>
		<p>A layout with four simple columns. Recommended for thematic landing pages where you have many different types of content to display.</p> 
	</div>
</div>

<!-- Content Landing Page Type 4 -->
<div class="page-thumbnail-container inactive" id="content_landing_page_type_4">
	<div class="inner">
<?php
print theme('image',array('path'=>drupal_get_path('module','idap_workbench').'/page_thumbnails/content_landing_page_type_4.png','attributes'=>array('class'=>array('page-thumbnail'),'id'=>'content-landing-page-type-1-thumbnail'))); ?>
		<p>A horizontal layout. Blocks are four-columns wide and stacked vertically. This is recommended for places where you have content which may take up varying amounts of vertical space.</p> 
	</div>
</div>

<!-- Content Landing Page Type 5 -->
<div class="page-thumbnail-container inactive" id="content_landing_page_type_5">
	<div class="inner">
<?php
print theme('image',array('path'=>drupal_get_path('module','idap_workbench').'/page_thumbnails/content_landing_page_type_5.png','attributes'=>array('class'=>array('page-thumbnail'),'id'=>'content-landing-page-type-1-thumbnail'))); ?>
		<p>A four-column layout with a large highlight box at the top with four single columns below. Recommended for where you need to provide introductory text alongside other content.</p> 
	</div>
</div>

<div class="clearfix"></div>
<?php print drupal_render_children($form); ?>