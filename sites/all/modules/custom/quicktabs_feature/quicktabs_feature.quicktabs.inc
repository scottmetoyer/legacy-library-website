<?php
/**
 * @file
 * quicktabs_feature.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function quicktabs_feature_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'collections';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Collections';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'collections',
      'display' => 'block_1',
      'args' => '',
      'title' => 'Notable Collections',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'machine_name' => 'collections_subject_areas',
      'title' => 'Subject Areas',
      'weight' => '-99',
      'type' => 'qtabs',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Collections');
  t('Notable Collections');
  t('Subject Areas');

  $export['collections'] = $quicktabs;

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'collections_subject_areas';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Collections - Subject Areas';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'collections',
      'display' => 'block_2',
      'args' => '159',
      'title' => 'Arts & Humanities',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'collections',
      'display' => 'block_2',
      'args' => '160',
      'title' => 'Agriculture',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'collections',
      'display' => 'block_2',
      'args' => '161',
      'title' => 'Medicine',
      'weight' => '-98',
      'type' => 'view',
    ),
    3 => array(
      'vid' => 'collections',
      'display' => 'block_2',
      'args' => '162',
      'title' => 'Social Sciences',
      'weight' => '-97',
      'type' => 'view',
    ),
    4 => array(
      'vid' => 'collections',
      'display' => 'block_2',
      'args' => '163',
      'title' => 'Science, Technology, Engineering & Math',
      'weight' => '-96',
      'type' => 'view',
    ),
    5 => array(
      'vid' => 'collections',
      'display' => 'block_2',
      'args' => '164',
      'title' => 'Business, Education, & Public Policy',
      'weight' => '-95',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Agriculture');
  t('Arts & Humanities');
  t('Business, Education, & Public Policy');
  t('Collections - Subject Areas');
  t('Medicine');
  t('Science, Technology, Engineering & Math');
  t('Social Sciences');

  $export['collections_subject_areas'] = $quicktabs;

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'directory';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Directory';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'departments',
      'display' => 'block_1',
      'args' => '',
      'title' => 'Departments & Services',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'staff',
      'display' => 'block_2',
      'args' => '',
      'title' => 'Staff',
      'weight' => '-99',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Departments & Services');
  t('Directory');
  t('Staff');

  $export['directory'] = $quicktabs;

  return $export;
}
