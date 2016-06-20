<?php
/**
 * @file
 * Form template functions.
 */

/**
 * Implements hook_form_alter().
 */
function ucrlib_form_alter(&$form, &$form_state, $form_id) {
  // dpm($form);

  if ($form_id == 'search_block_form') {
    // Add placeholder text
    $form['search_block_form']['#attributes']['placeholder'] = t('Search catalog, website & more...');
  }
  elseif ($form['#id'] == 'views-exposed-form-search-page-page' ||
          $form['#id'] == 'views-exposed-form-search-page-page-1') {
    // Add placeholder text
    $form['search_api_views_fulltext']['#attributes']['placeholder'] = t('Search catalog, website & more...');
  }
}
