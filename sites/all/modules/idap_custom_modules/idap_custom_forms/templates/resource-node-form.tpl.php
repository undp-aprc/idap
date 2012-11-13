<div class="node-add-wrapper resource-node-form">
	<div class="node-main">
		<?php if($node_main): ?>
	      	<?php print render($node_main); ?>
	    <?php endif; ?>
	<div style="height:20px;"></div>
  	<div class="node-column-main">
		<div class="enclosure">
			<div id="resource-content">
				<div id="tabs">
					<ul>
							<li><a href="#resource-file"><?php print t('Resource File'); ?></a></li>
							<li><a href="#resource-link"><?php print(t('Resource Link'))?></a></li>
						</ul>
						<div id="resource-file">
							<?php if($form['field_resource_file']): ?>
								<?php print render($form['field_resource_file']); ?>
							<?php endif; ?>
						</div>
						<div id="resource-link">
							<?php if($form['field_resource_url']): ?>
								<?php print render($form['field_resource_url']); ?>
							<?php endif; ?>
						</div>
				</div>
			</div>
		</div>
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
		<h3><?php print t('Content Audience Options'); ?></h3>
		<p class="dark-grey"><?php print t('By using the options below you can choose where your content will be displayed within this site\'s sub-theme pages, block and groups.'); ?></p>
	    <?php if($sidebar): ?>
	      	<?php print render($sidebar); ?>
	    <?php endif; ?>
		</div>
	</div>
  <div class="clearfix"></div>
</div>