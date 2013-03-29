<div class="node-add-wrapper thematic-home-page-4-node-form">
	<div class="node-main">
		<?php if($node_main): ?>
	      	<?php print render($node_main); ?>
	    <?php endif; ?>
		<div id="content">
			<div class="user-content-blocks blocks container-blocks">
				<div id="user-content-blocks-1" class="blocks container-blocks colPos-0 col-4"> 
					<div class="content-block block first odd">
						<div class="inner-block highlight">
							<?php if ($block_1): ?>
								<?php print render($block_1); ?>
							<?php endif; ?>
						</div>
					</div>
				</div> <!-- user-content-blocks-1 -->
				<div id="user-content-blocks-2" class="blocks container-blocks"> <!-- The main container for content blocks with be user-content-blocks on sub-theme pages as this will allow us to wrap block regions into containers and place blocks within those containers using Drupal entity references. The reason for this is to allow us to create advanced custom page layouts for blocks -->
					<div class="content-block block first odd colPos-0 col-4">
						<div class="inner-block">
							<?php if ($block_2): ?>
								<?php print render($block_2); ?>
							<?php endif; ?>
						</div>
					</div>
				</div> <!-- user-content-blocks-2 -->
				<div id="user-content-blocks-3" class="blocks container-blocks"> <!-- The main container for content blocks with be user-content-blocks on sub-theme pages as this will allow us to wrap block regions into containers and place blocks within those containers using Drupal entity references. The reason for this is to allow us to create advanced custom page layouts for blocks -->
					<div class="content-block block first odd col-4 colPos-0">
						<div class="inner-block">
							<?php if ($block_3): ?>
								<?php print render($block_3); ?>
							<?php endif; ?>
						</div>
					</div>
				</div> <!-- user-content-blocks-3 -->
				<div id="user-content-blocks-4" class="blocks container-blocks"> <!-- The main container for content blocks with be user-content-blocks on sub-theme pages as this will allow us to wrap block regions into containers and place blocks within those containers using Drupal entity references. The reason for this is to allow us to create advanced custom page layouts for blocks -->
					<div class="content-block block first odd col-4 colPos-0">
						<div class="inner-block">
							<?php if ($block_4): ?>
								<?php print render($block_4); ?>
							<?php endif; ?>
						</div>
					</div>
				</div> <!-- user-content-blocks-4 -->
				<div id="user-content-blocks-5" class="blocks container-blocks"> <!-- The main container for content blocks with be user-content-blocks on sub-theme pages as this will allow us to wrap block regions into containers and place blocks within those containers using Drupal entity references. The reason for this is to allow us to create advanced custom page layouts for blocks -->
					<div class="content-block block first odd col-4 colPos-0">
						<div class="inner-block">
							<?php if ($block_5): ?>
								<?php print render($block_5); ?>
							<?php endif; ?>
						</div>
					</div>
				</div> <!-- user-content-blocks-5 -->
				<div id="user-content-blocks-6" class="blocks container-blocks"> <!-- The main container for content blocks with be user-content-blocks on sub-theme pages as this will allow us to wrap block regions into containers and place blocks within those containers using Drupal entity references. The reason for this is to allow us to create advanced custom page layouts for blocks -->
					<div class="content-block block first odd col-4 colPos-0">
						<div class="inner-block">
							<?php if ($block_6): ?>
								<?php print render($block_6); ?>
							<?php endif; ?>
						</div>
					</div>
				</div> <!-- user-content-blocks-6 -->
			</div> <!-- container-blocks -->
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