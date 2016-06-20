<?php
/**
 * @file
 * Menu template functions.
 */

/**
 * Implements theme_menu_tree().
 */
function ucrlib_menu_tree(&$vars) {
  return '<ul class="nav nav-inline">' . $vars['tree'] . '</ul>';
}

/**
 * Implements theme_menu_tree() for the main menu.
 */
function ucrlib_menu_tree__main_menu(&$vars) {
  return '<ul class="nav">' . $vars['tree'] . '</ul>';
}

/**
 * Implements hook_preprocess_menu_link().
 */
function ucrlib_preprocess_menu_link(&$vars) {
  // Set shortcut variables. Hooray for less typing!
  $menu = $vars['element']['#original_link']['menu_name'];
  $mlid = $vars['element']['#original_link']['mlid'];
  $item_classes = &$vars['element']['#attributes']['class'];
  $link_classes = &$vars['element']['#localized_options']['attributes']['class'];

  // Add depth of menu item
  $depth = '';
  if (isset($vars['element']['#original_link']['depth'])) {
    $depth = 'level-' . $vars['element']['#original_link']['depth'];
  }

  // Add global classes to all menu links
  $item_classes[] = 'nav-item';
  $item_classes[] = $menu . '__nav-item';
  $item_classes[] = 'nav-item--' . $depth;
  $item_classes[] = $menu . '__nav-item--' . $depth;
  $link_classes[] = 'nav-link';
  $link_classes[] = $menu . '__nav-link';
  $link_classes[] = 'nav-link--' . $depth;
  $link_classes[] = $menu . '__nav-link--' . $depth;
}
