<ul>
	<?php foreach($element['menu_tree'] as $item=>$array): ?>
		<li>
			<?php print l($array['link']['link_title'], $array['link']['link_path']); ?>
		</li>
	<?php endforeach; ?>
</ul>