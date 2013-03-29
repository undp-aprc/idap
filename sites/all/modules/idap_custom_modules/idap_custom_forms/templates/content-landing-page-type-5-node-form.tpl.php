<div class="node-add-wrapper thematic-home-page-5-node-form">
	<div class="node-main">
		<?php if($node_main): ?>
	      	<?php print render($node_main); ?>
	    <?php endif; ?>
		<div id="content">
			<div class="region-content-blocks blocks">
				<div class="content-block block col-4 colPos-0 first odd">
					<div class="inner-block highlight">
						<?php if ($block_1): ?>
							<?php print render($block_1); ?>
						<?php endif; ?>
					</div>
				</div>
				<div class="content-block block col-1 colPos-0 even">
					<div class="inner-block">
						<?php if ($block_2): ?>
							<?php print render($block_2); ?>
						<?php endif; ?>
					</div>
				</div>
				<div class="content-block block col-1 colPos-1 odd">
					<div class="inner-block">
						<div class="block-content block">
							<div class="inner-block">
								<?php if ($block_3): ?>
									<?php print render($block_3); ?>
								<?php endif; ?>
							</div>
						</div>
				 	</div>
				</div>
				<div class="content-block block col-1 colPos-2 first odd">
					<div class="inner-block">
						<?php if ($block_4): ?>
							<?php print render($block_4); ?>
						<?php endif; ?>
					</div>
				</div>
				<div class="content-block block col-1 colPos-3 last even">
					<div class="inner-block">
						<?php if ($block_5): ?>
							<?php print render($block_5); ?>
						<?php endif; ?>
				 	</div>
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