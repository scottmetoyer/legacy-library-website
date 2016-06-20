<?php
/**
 * @file
 * Panels template functions.
 */

/**
 * Implements template_preprocess_panels_pane().
 */
function ucrlib_preprocess_panels_pane(&$vars) {
  $subtype = isset($vars['pane']->subtype) ? $vars['pane']->subtype : FALSE;
  $layout = isset($vars['display']->layout) ? $vars['display']->layout : FALSE;

  if ($subtype) {
    $vars['theme_hook_suggestions'][] = 'panels_pane__' . $subtype;
  }
  if ($layout) {
    $vars['theme_hook_suggestions'][] = 'panels_pane__' . $layout;
  }
  if ($subtype && $layout) {
    $vars['theme_hook_suggestions'][] = 'panels_pane__' . $layout . '__' . $subtype;
  }
}
