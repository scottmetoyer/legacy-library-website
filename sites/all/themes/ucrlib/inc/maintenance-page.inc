<?php
/**
 * @file
 * Maintenance page template functions.
 */

/**
 * Implements hook_preprocess_maintenance_page().
 */
function ucrlib_preprocess_maintenance_page(&$vars, $hook) {
  // When a variable is manipulated or added in preprocess_html or
  // preprocess_page, that same work is probably needed for the maintenance page
  // as well, so we can just re-use those functions to do that work here.
  // ucrlib_preprocess_html($variables, $hook);
  // ucrlib_preprocess_page($variables, $hook);

  // This preprocessor will also be used if the db is inactive. To ensure your
  // theme is used, add the following line to your settings.php file:
  // $conf['maintenance_theme'] = 'ucrlib';
  // Also, check $vars['db_is_active'] before doing any db queries.

  $css_options = array(
    'group' => CSS_THEME,
    'every_page' => TRUE,
    'weight' => 9999,
    'preprocess' => FALSE,
  );
  drupal_add_css(path_to_theme() . '/css/maintenance.css', $css_options);
}

/**
 * Implements hook_process_maintenance_page().
 */
function ucrlib_process_maintenance_page(&$vars, $hook) {
  // When a variable is manipulated or added in preprocess_html or
  // preprocess_page, that same work is probably needed for the maintenance page
  // as well, so we can just re-use those functions to do that work here.
  // ucrlib_process_html($variables, $hook);
  // ucrlib_process_page($variables, $hook);

  // This preprocessor will also be used if the db is inactive. To ensure your
  // theme is used, add the following line to your settings.php file:
  // $conf['maintenance_theme'] = 'ucrlib';
  // Also, check $vars['db_is_active'] before doing any db queries.
}
