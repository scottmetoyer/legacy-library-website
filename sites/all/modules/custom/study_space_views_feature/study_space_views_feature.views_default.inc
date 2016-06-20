<?php
/**
 * @file
 * study_space_views_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function study_space_views_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'study_spaces';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Study Spaces';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Study Spaces';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_study_space_features_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_library_target_id' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
    'bef_filter_description' => NULL,
    'any_label' => NULL,
    'filter_rewrite_values' => NULL,
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'full_html';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_library' => 'field_library',
    'field_floor' => 'field_floor',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = 'field_library';
  $handler->display->display_options['style_options']['info'] = array(
    'field_library' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_floor' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p class="big">We provide spaces in all four libraries for different learning styles. Food and drink are allowed in almost all areas.</p>



';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Content: Library */
  $handler->display->display_options['fields']['field_library']['id'] = 'field_library';
  $handler->display->display_options['fields']['field_library']['table'] = 'field_data_field_library';
  $handler->display->display_options['fields']['field_library']['field'] = 'field_library';
  $handler->display->display_options['fields']['field_library']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field: Floor */
  $handler->display->display_options['fields']['field_floor']['id'] = 'field_floor';
  $handler->display->display_options['fields']['field_floor']['table'] = 'field_data_field_floor';
  $handler->display->display_options['fields']['field_floor']['field'] = 'field_floor';
  $handler->display->display_options['fields']['field_floor']['label'] = 'Location';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Space';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Reserve room link */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['label'] = 'Reserve';
  $handler->display->display_options['fields']['field_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link']['alter']['text'] = '<a class="button"></a>';
  $handler->display->display_options['fields']['field_link']['alter']['path'] = '[field_link-url]';
  $handler->display->display_options['fields']['field_link']['element_class'] = 'button';
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_label';
  /* Field: Field: Reserve room link */
  $handler->display->display_options['fields']['field_link_1']['id'] = 'field_link_1';
  $handler->display->display_options['fields']['field_link_1']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link_1']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link_1']['label'] = 'Reserve';
  $handler->display->display_options['fields']['field_link_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_link_1']['alter']['text'] = '<a class="button" href="http://ucr.evanced.info/dibs/Login">Reserve</a>';
  $handler->display->display_options['fields']['field_link_1']['click_sort_column'] = 'url';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'study_space' => 'study_space',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Features (field_study_space_features) */
  $handler->display->display_options['filters']['field_study_space_features_tid']['id'] = 'field_study_space_features_tid';
  $handler->display->display_options['filters']['field_study_space_features_tid']['table'] = 'field_data_field_study_space_features';
  $handler->display->display_options['filters']['field_study_space_features_tid']['field'] = 'field_study_space_features_tid';
  $handler->display->display_options['filters']['field_study_space_features_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_study_space_features_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_study_space_features_tid']['expose']['operator_id'] = 'field_study_space_features_tid_op';
  $handler->display->display_options['filters']['field_study_space_features_tid']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_study_space_features_tid']['expose']['operator'] = 'field_study_space_features_tid_op';
  $handler->display->display_options['filters']['field_study_space_features_tid']['expose']['identifier'] = 'f';
  $handler->display->display_options['filters']['field_study_space_features_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_study_space_features_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_study_space_features_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_study_space_features_tid']['vocabulary'] = 'study_space_features';
  /* Filter criterion: Content: Library (field_library) */
  $handler->display->display_options['filters']['field_library_target_id']['id'] = 'field_library_target_id';
  $handler->display->display_options['filters']['field_library_target_id']['table'] = 'field_data_field_library';
  $handler->display->display_options['filters']['field_library_target_id']['field'] = 'field_library_target_id';
  $handler->display->display_options['filters']['field_library_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_library_target_id']['expose']['operator_id'] = 'field_library_target_id_op';
  $handler->display->display_options['filters']['field_library_target_id']['expose']['label'] = 'Library';
  $handler->display->display_options['filters']['field_library_target_id']['expose']['operator'] = 'field_library_target_id_op';
  $handler->display->display_options['filters']['field_library_target_id']['expose']['identifier'] = 'l';
  $handler->display->display_options['filters']['field_library_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_library_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );

  /* Display: Study spaces page */
  $handler = $view->new_display('page', 'Study spaces page', 'page');
  $handler->display->display_options['path'] = 'using-the-library/study-spaces';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Study Spaces';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['study_spaces'] = $view;

  return $export;
}
