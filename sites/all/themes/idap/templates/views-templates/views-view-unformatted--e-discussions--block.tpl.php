<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<div class="clearfix"></div>
<?php if (!empty($title)): ?>
  <h2><?php print $title; ?></h2>
<?php endif; ?>
<div class="content block-content-item">
<ul>
<?php foreach ($rows as $id => $row): ?>
  <li><?php print $row; ?></li>
<?php endforeach; ?>
</ul>
</div>
<div class="clearfix"></div>