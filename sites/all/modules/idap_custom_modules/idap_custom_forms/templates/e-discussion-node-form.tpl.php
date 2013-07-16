<div style="height:20px;"></div>
<div class="e-discussion-node-add-wrapper e-discussion-node-form">
  	<div class="node-column-main">
		<div class="enclosure">
    	<?php if($form): ?>
      		<?php print drupal_render_children($form); ?>
    	<?php endif; ?>
		<?php if($buttons): ?>
	      <div class="node-buttons">
	        <?php print render($buttons); ?>
	    </div>
	  	<?php endif; ?>
		</div>
  	</div>
  	<div class="node-column-sidebar highlight">
		<div class="enclosure">
		<h3>Content Audience Options</h3>
		<p class="dark-grey"><?php print t('By using the options below you can choose where your content will be displayed within this site\'s sub-theme pages, block and groups.'); ?></p>
	    <?php if($sidebar): ?>
	      	<?php print render($sidebar); ?>
	    <?php endif; ?>
		</div>
	</div>
  <div class="clearfix"></div>
</div>