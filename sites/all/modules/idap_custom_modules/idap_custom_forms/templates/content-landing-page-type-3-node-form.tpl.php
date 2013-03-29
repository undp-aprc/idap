<div class="node-add-wrapper thematic-home-page-3-node-form">
	<div class="node-main">
		<?php if($node_main): ?>
	      	<?php print render($node_main); ?>
	    <?php endif; ?>
		<div id="content">
			<div class="region-content-blocks blocks container-blocks">
				<div class="content-block block col-1 first colPos-0 odd">
					<div class="inner-block">
						<?php if ($block_1): ?>
							<?php print render($block_1); ?>
						<?php endif; ?>
						<?php if ($block_2): ?>
							<?php print render($block_2); ?>
						<?php endif; ?>
					</div>
				</div>
				<div class="content-block block col-1 first colPos-1 even">
					<div class="inner-block">
						<?php if ($block_3): ?>
							<?php print render($block_3); ?>
						<?php endif; ?>
						<?php if ($block_4): ?>
							<?php print render($block_4); ?>
						<?php endif; ?>
					</div> <!-- .inner-block -->
				</div>
				<div class="content-block block col-1 colPos-2 odd">
				<div class="inner-block">
						<?php if ($block_5): ?>
							<?php print render($block_5); ?>
						<?php endif; ?>
						<?php if ($block_6): ?>
							<?php print render($block_6); ?>
						<?php endif; ?>
				</div> <!-- .inner-block -->
				</div>
				<div class="content-block block col-1 last colPos-3 even">
					<div class="inner-block">
						<?php if ($block_7): ?>
							<?php print render($block_7); ?>
						<?php endif; ?>
						<?php if ($block_8): ?>
							<?php print render($block_8); ?>
						<?php endif; ?>
					</div> <!-- .inner-block -->
				</div>
			</div> <!-- region-content-blocks -->
			<div class="clearfix"></div>
		<?php if($form): ?>
      		<?php print drupal_render_children($form); ?>
    	<?php endif; ?>
		<?php if($buttons): ?>
	      <div class="node-buttons">
	        <?php print render($buttons); ?>
	      </div>
	  	<?php endif; ?>
  	</div>
  <div class="clearfix"></div>
</div>