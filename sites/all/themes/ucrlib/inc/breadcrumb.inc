<?php
/**
 * @file
 * Breadcrumb template functions.
 */

/**
 * Implements theme_breadcrumb().
 */
function ucrlib_breadcrumb(&$vars) {
  $breadcrumb = $vars['breadcrumb'];

  if (!empty($breadcrumb)) {
    $before = '<span class="breadcrumb__link">';
    $after = '</span>';
    $breadcrumb_separator = '<span class="breadcrumb__separator"> / </span>';
    $title = '<span class="breadcrumb__page-title">' . drupal_get_title() . '</span>';

    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';
    $output .= '<div class="breadcrumb">';
    $output .= $before . implode($after . $breadcrumb_separator . $before, $breadcrumb) . $after . $breadcrumb_separator . $title;
    $output .= '</div>';

    return $output;
  }

}
