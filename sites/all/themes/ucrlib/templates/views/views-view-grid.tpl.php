<?php

/**
 * @file
 * Default simple view template to display a rows in a grid.
 *
 * - $rows contains a nested array of rows. Each row contains an array of
 *   columns.
 *
 * @ingroup views_templates
 */
?>
<?php
reset($rows);
$gridsize = count($rows[0]);
?>

<?php if (!empty($title)) : ?>
  <h3 class='grid-title'><?php print $title; ?></h3>
<?php endif; ?>
<div class="views-view-grid grid-<?php print $gridsize ?>-col">

  <?php foreach ($rows as $row_number => $columns): ?>
    <?php
    $row_class = 'row-' . ($row_number + 1);
    if ($row_number == 0 && count($rows) > 1) {
      $row_class .= ' row-first';
    }
    elseif (count($rows) == ($row_number + 1)) {
      $row_class .= ' row-last';
    }
    ?>
    <div class="row <?php print $row_class; ?>">
      <?php foreach ($columns as $col_number => $item): ?>
        <?php
        $col_class = 'col-' . ($col_number + 1);
        if ($col_number == 0 && count($columns) > 1) {
          $col_class .= ' col-first';
        }
        elseif (count($columns) == ($col_number + 1)) {
          $col_class .= ' col-last';
        }
        ?>
        <div class="col <?php print $col_class; ?>">
          <?php if ($item): ?>
            <div class='inside'>
              <?php print $item; ?>
            </div>
          <?php endif; ?>
        </div>
      <?php endforeach; ?>
    </div>
  <?php endforeach; ?>
</div>
