<div class="stripe-top"><span>Development Themes</span></div>
<div class="items">
	<ul class="level-1">
		<?php foreach($element['menu_tree'] as $item=>$array): ?>
			<li class="level-1-li"><div class="level-1-background"><?php print $array['link']['link_title']; ?></div>
			<div class="has-background"></div>
			<?php if (count($array['below']) > 0): ?>
				<ul class="level-2">
					<?php foreach ($array['below'] as $item_secondary=>$array_secondary): ?>
						<li class="level-2-li">
							<?php print l($array_secondary['link']['link_title'], $array_secondary['link']['link_path']); ?>
						</li>
					<?php endforeach; ?>
				</ul>
			<?php endif; ?>
			</li>
		<?php endforeach; ?>
	</ul>
</div> <!-- .items -->
<div class="stripe-bottom"></div>