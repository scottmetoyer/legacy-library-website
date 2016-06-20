<?php
/**
 * @file
 * Page template functions.
 */

/**
 * Implements hook_preprocess_page().
 */
function ucrlib_preprocess_page(&$vars) {
  // dpm($vars);

  // Drupal core doesn't add "active" to /user.
  // Let's fix it.
  if (isset($vars['user'])) {
    if (drupal_match_path(current_path(), 'user' . chr(10). 'user/*')) {
      menu_set_active_item('user');
    }
  }

  // Specify where the page title is rendered.
  // Nodes:
  if (isset($vars['node']->type)) {

    switch ($vars['node']->type) {
      case 'department':
      case 'exhibit':
      case 'jump_page':
      case 'library':
      case 'minimal_page':
      case 'news':
      case 'page':
      case 'subject_guide':
        $vars['inner_title'] = TRUE;
        break;

      case '':
        $vars['outer_title'] = TRUE;
        break;

      default:
        // No title will render.
        break;
    }

    // Theme suggestions based on type
    $vars['theme_hook_suggestions'][] = 'page__node__' . $vars['node']->type;
  }
  // Views:
  elseif (function_exists('views_get_page_view') && $page = views_get_page_view()) {
    // dpm($page->name);

    switch ($page->name) {
      case 'search_page':
        $vars['outer_title'] = FALSE;
        $vars['inner_title'] = FALSE;
        break;

      case '';
        $vars['outer_title'] = TRUE;
        break;

      default:
        $vars['inner_title'] = TRUE;
        break;
    }
  }

  // Override above with a Context:
  if (function_exists('context_active_contexts') && $contexts = context_active_contexts()) {
    // dpm($contexts);

    if (array_key_exists('about_section', $contexts)) {
      $vars['inner_title'] = TRUE;
      unset($vars['outer_title']);
    }
    if (array_key_exists('exhibits', $contexts)) {
      unset($vars['inner_title']);
      $vars['outer_title'] = TRUE;
    }
  }
}
