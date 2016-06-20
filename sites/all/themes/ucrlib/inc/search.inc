<?php
/**
 * @file
 * Search template functions.
 */

/**
 * Implements template_preprocess_search_results().
 */
function ucrlib_preprocess_search_results(&$vars) {
  // dpm($vars, 'RESULTS');

  // search.module shows 10 items per page (this isn't customizable)
  $items_per_page = 10;

  // Determine which page is being viewed
  // If $_REQUEST['page'] is not set, we are on page 1
  $current_page = (isset($_REQUEST['page']) ? $_REQUEST['page'] : 0) + 1;

  // Get the total number of results from the global pager
  $total = $GLOBALS['pager_total_items'][0];

  // Determine which results are being shown ("Showing results x through y")
  $start = (10 * $current_page) - 9;
  // If on the last page, only go up to $total, not the total that COULD be
  // shown on the page. This prevents things like "Displaying 11-20 of 17".
  $end = (($items_per_page * $current_page) >= $total) ? $total : ($items_per_page * $current_page);

  $vars['search_totals'] = t('Found !total results containing the words: !words', array(
    '!total' => $total,
    '!words' => 'search words',
  ));
}

/**
 * Implements template_preprocess_search_result().
 */
function ucrlib_preprocess_search_result(&$vars) {
  // dpm($vars, 'RESULT');
}
