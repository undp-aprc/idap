<div class="node-add-wrapper thematic-home-page-1-node-form">
	<div class="node-main">
		<?php if($node_main): ?><?php print render($node_main); ?><?php endif; ?>
		<div id="content">
			<div typeof="sioc:Item foaf:Document" about="/mdg-acceleration/news" class="node node-content-landing-page-type-1 clearfix" id="node-81">
				<div class="user-content-blocks blocks container-blocks equal-column-heights" id="user-content-blocks-1">
					<!-- The main container for content blocks with be user-content-blocks on sub-theme pages as this will allow us to wrap block regions into containers and place blocks within those containers using Drupal entity references. The reason for this is to allow us to create advanced custom page layouts for blocks -->
					<div class="content-block block news-block col-3 first odd colPos-0 rowNum-1">
						<div class="inner-block highlight equal-column-heights">
							<!-- Begin Block -->
							<?php if ($block_1): ?>
								<?php print render($block_1); ?>
							<?php endif; ?>
							</div><!-- End Block -->
						</div>
				</div><!-- #user-content-blocks-1 -->
				<div class="user-content-blocks blocks container-blocks equal-column-heights" id="user-content-blocks-2">
					<!-- The main container for content blocks with be user-content-blocks on sub-theme pages as this will allow us to wrap block regions into containers and place blocks within those containers using Drupal entity references. The reason for this is to allow us to create advanced custom page layouts for blocks -->
					<div class="content-block block col-1 colPos-2 odd colPos--3 rowNum-2">
						<div class="inner-block">
							<?php if ($block_2): ?>
								<?php print render($block_2); ?>
							<?php endif; ?>
						</div>
					</div>
				</div><!-- #user-content-blocks-2 -->
				<div style="margin-bottom:20px;" class="clearfix"></div>
			</div>
		</div>
		<?php if($form): ?><?php print drupal_render_children($form); ?><?php endif; ?><?php if($buttons): ?>
		<div class="node-buttons">
			<?php print render($buttons); ?>
		</div><?php endif; ?>
	</div>
	<div class="clearfix"></div>
</div>