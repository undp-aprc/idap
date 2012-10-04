<div class="node-add-wrapper thematic-home-page-1-node-form">
	<div class="node-main">
		<?php if($node_main): ?>
	      	<?php print render($node_main); ?>
	    <?php endif; ?>
		<div id="content">
								<div class="form-content-blocks blocks container-blocks" id="form-content-blocks-1"> <!-- The main container for content blocks with be form-content-blocks on sub-theme pages as this will allow us to wrap block regions into containers and place blocks within those containers using Drupal entity references. The reason for this is to allow us to create advanced custom page layouts for blocks -->
									<div class="content-block block news-block col-2 first odd colPos-0 rowNum-1">
										<div class="inner-block highlight">
											<div class="block-heading">
												<h2><?php //print t('Block 1'); ?></h2>
												<div class="clearfix"></div>
											</div>
											<div class="clearfix block-heading-divider"></div>
											<div class="block-content">
												<?php if ($block_1): ?>
													<?php print render($block_1); ?>
												<?php endif; ?>
												<div class="clearfix"></div>
												<div class="sub-block-content inline col-1 first ">
													<h3><?php //print t('Block 2'); ?></h3>
													<?php if ($block_2): ?>
														<?php print render($block_2); ?>
													<?php endif; ?>
										 		</div>
												<div class="sub-block-content inline col-1 last ">
													<h3><?php //print t('Block 3'); ?></h3>
													<?php if ($block_3): ?>
														<?php print render($block_3); ?>
													<?php endif; ?>
										 		</div>
												<div class="clearfix"></div>
											</div>
										</div>
									</div>
								</div> <!-- #form-content-blocks-1 -->
								<div class="form-content-blocks blocks container-blocks" id="form-content-blocks-2"> <!-- The main container for content blocks with be form-content-blocks on sub-theme pages as this will allow us to wrap block regions into containers and place blocks within those containers using Drupal entity references. The reason for this is to allow us to create advanced custom page layouts for blocks -->
										<div class="content-block block resources-block col-1 odd  colPos-2 rowNum-3">
											<div class="inner-block">
												<div class="block-heading">
													<h2><?php //print t('Block 5'); ?></h2>
												</div>
												<div class="clearfix block-heading-divider"></div>
												<div class="block-content">
													<?php if ($block_4): ?>
														<?php print render($block_4); ?>
													<?php endif; ?>
									 			</div>
											</div>
										</div>
								</div> <!-- #form-content-blocks-2 -->
								<div class="form-content-blocks blocks container-blocks" id="form-content-blocks-3"> <!-- The main container for content blocks with be form-content-blocks on sub-theme pages as this will allow us to wrap block regions into containers and place blocks within those containers using Drupal entity references. The reason for this is to allow us to create advanced custom page layouts for blocks -->
										<div class="content-block block blogs-block col-1 last even  colPos-3 rowNum-4">
											<div class="inner-block">
												<div class="block-heading">
													<h2><?php //print t('Block 6'); ?></h2>
												</div>
												<div class="clearfix block-heading-divider"></div>
												<div class="block-content">
													<?php if ($block_5): ?>
														<?php print render($block_5); ?>
													<?php endif; ?>
											 	</div>
											</div> <!-- .inner-block -->
										</div>
								</div> <!-- #form-content-blocks-3 -->
								<div class="form-content-blocks blocks container-blocks" id="form-content-blocks-4"> <!-- The main container for content blocks with be form-content-blocks on sub-theme pages as this will allow us to wrap block regions into containers and place blocks within those containers using Drupal entity references. The reason for this is to allow us to create advanced custom page layouts for blocks -->
									<div class="content-block block col-4 colPos-0 rowNum-2">
										<div class="inner-block">
											<div class="block-heading">
												<h2><?php //print t('Block 4'); ?></h2>
											</div>
											<div class="clearfix block-heading-divider"></div>
											<div class="block-content">
												<?php if ($block_6): ?>
													<?php print render($block_6); ?>
												<?php endif; ?>
										 	</div>
										</div> <!-- .inner-block -->
									</div>

								</div> <!-- #form-content-blocks-4 -->
								<div class="clearfix"></div>
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
  <div class="clearfix"></div>
</div>