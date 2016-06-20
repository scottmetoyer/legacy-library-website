<?php
/**
 * @file
 * Template for rendering opening hours week.
 */
?>
<div class="ucrlib-opening-hours-week" data-nid="<?php print $nid; ?>" data-date="<?php print $date; ?>">
  <div class="ucrlib-opening-hours-table">
    <table>
      <thead>
        <tr>
          <th class="week"><?php print $week; ?></th>
          <?php foreach ($header as $day_key => $day): ?>
            <th <?php if ($header_classes[$day_key]) { print 'class="' . implode(' ', $header_classes[$day_key]) .'"';  } ?>><?php print $day; ?></th>
          <?php endforeach; ?>
        </tr>
      </thead>
      <tbody>
        <?php   $count=0;
        		foreach ($locations as $location_key => $location): ?>
          <tr <?php if ($location_classes[$location_key]) { print 'class="' . implode(' ', $location_classes[$location_key]) .'"';  } ?>>
            <?php if($count!=0){ ?>
            <th class="table_header"><?php print $location['title']; }?></th>
            <?php if($count==0)
            {?>
            <th class="table_header_bold"><?php print $location['title']; ?></th>
            <?php }?>
            <?php foreach ($location['days'] as $day_key => $day): ?>
              <td <?php if ($day_classes[$location_key][$day_key]) { print 'class="' . implode(' ', $day_classes[$location_key][$day_key]) .'"';  } ?> data-label="<?php print $day['label'] ?>"><?php print $day['status']; ?></td>
            <?php endforeach; ?>
          </tr>
        <?php
        $count++;
        endforeach; ?>
      </tbody>
    </table>
  </div>
</div>
