<?php
/**
 * @file
 * Block template functions.
 */

/**
 * Implements hook_preprocess_block().
 */
function ucrlib_preprocess_block(&$vars) {
  // Set shortcut variables. Hooray for less typing!
  $block_id = $vars['block']->module . '-' . $vars['block']->delta;
  $classes = &$vars['classes_array'];
  $title_classes = &$vars['title_attributes_array']['class'];
  $content_classes = &$vars['content_attributes_array']['class'];

  // Region where block is rendered
  $regioned_block = '';
  if (isset($vars['elements']['#block']->region)) {
    $regioned_block = $block_id . '@' . $vars['elements']['#block']->region;
  }

  // Custom block wrapper html element.
  $vars['wrapper_element'] = 'div';
  $wrapper_element = &$vars['wrapper_element'];

  // Use a content wrapper
  $vars['use_content_wrapper'] = TRUE;
  $use_content_wrapper = &$vars['use_content_wrapper'];

  // Add global classes to all blocks.
  $title_classes[] = 'block-title';
  $content_classes[] = 'block-content';

  // print $block_id . '<br/>';
  // print $vars['block']->module . '<br/>';
  // print $vars['elements']['#block']->region . '<br/> ';
  // dpm($regioned_block);
  // dpm($vars);
  // dpm($vars['block']);

  if ($vars['block']->module == 'menu_block' && isset($vars['elements']['#block']->region)) {
    $classes[] = drupal_html_class($vars['elements']['#block']->region) . '-nav';
  }

  // Add classes based on location & the block delta.
  switch ($regioned_block) {
    // Main Menu block
    case 'menu_block-1@main_nav':
    case 'menu_block-3@hidden':
      $classes[] = 'main-nav';
      $vars['block']->subject = '';
      break;
    // Main Menu block
    case 'menu-menu-utility@header_content':
      $classes[] = 'utility-nav--header';
      $vars['block']->subject = '';
      break;
    // Search block
    case 'views--exp-search_page-page_1@header_content':
    case 'search-form@header_content':
      $classes[] = 'search--header';
      break;
    case 'views--exp-search_page-page@banner':
    case 'search-form@banner':
      $classes[] = 'search--banner';
      break;
    case 'views--exp-search_page-page@content_prefix':
      $classes[] = 'search--results-page';
      break;
  }

  // Add classes based on block delta only.
  switch ($block_id) {
    // Footer libraries
    case 'views-libraries-block_1':
      $classes[] = 'footer-libraries';
      break;
    // Sidebar libraries
    case 'views-libraries-block_2':
      $classes[] = 'sidebar-libraries';
      break;
    // Directory tabs
    case 'quicktabs-directory':
      $classes[] = 'directory-list__tabs';
      $vars['block']->subject = '';
      break;
    // Directory tabs
    case 'quicktabs-collections':
      $classes[] = 'collections-list__tabs';
      $vars['block']->subject = '';
      break;
    // Homepage workshops/events
    case 'views-events-block_1':
      $classes[] = 'view-events--homepage-block';
      break;
    // Homepage news
    case 'views-news-block_2':
      $classes[] = 'view-news--homepage-block';
      break;
    // Filters block on databases page
    case 'views--exp-databases-page_1':
      $classes[] = 'view-database__filters-block';
      break;
    // Research Services page: databases
    case 'views-database_blocks-block_1':
      $classes[] = 'research-services__db-block';
      break;
    // Hours page: Hours
    case 'ucrlib_custom-hours':
      $classes[] = 'ucrlib-opening-hours-week-block';
      $vars['block']->subject = '';
      break;
    // Homepage/today: Hours
    case 'ucrlib_custom-today':
      $classes[] = 'ucrlib-opening-hours-today-block';
      break;
    // Ask a librarian: Hours
    case 'ucrlib_custom-librarians':
      $classes[] = 'ucrlib-opening-hours-ask-librarians-block';
      break;
    // Current search
    case 'current_search-default_node_index_block':
      $vars['block']->subject = '';
      break;
  }
}
