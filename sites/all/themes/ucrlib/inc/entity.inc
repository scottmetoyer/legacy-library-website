<?php
/**
 * @file
 * Entity template functions.
 */

/**
 * Implements hook_preprocess_entity().
 */
function ucrlib_preprocess_entity(&$vars, $hook) {
  $function = 'ucrlib_preprocess_' . $vars['entity_type'];
  if (function_exists($function)) {
    $function($vars, $hook);
  }
}
