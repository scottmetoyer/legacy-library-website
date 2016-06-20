<?php
/**
 * @file
 * Table functions.
 */

/**
 * Implements theme_tablesort_indicator().
 */
function ucrlib_tablesort_indicator($vars) {
  if ($vars ['style'] == "asc") {
    return '<i class="fa fa-sort-asc sort sort--asc" title="' . t('sort ascending') . '"></i>';
  }
  else {
    return '<i class="fa fa-sort-desc sort sort--desc" title="' . t('sort descending') . '"></i>';
  }
}
