<div class="summary-listing-photo">
	<div class="block-heading">
		<h2><?php print $title; ?></h2>
		<div class="clearfix"></div>
	</div>
	<div class="clearfix block-heading-divider"></div>
	<div class="block-main-content block-content">
		<div class="photo float-left">
			<?php print render($bean['photo']); ?>
		</div>
		<div class="content float-left">
			<ul>
				<?php print $block_content['node_items']; ?>
			</ul>
		</div>
		<div class="clearfix"></div>
	</div>
</div>