(function() {

  // Register the plugin
  CKEDITOR.plugins.add('fontawesome', {
    init: function(editor) {

      // Define an editor command that opens our dialog window.
      editor.addCommand('fontawesome', new CKEDITOR.dialogCommand('fontawesomeDialog'));

      // Create a toolbar button that executes the above command.
      editor.ui.addButton('wysiwyg-widget-fontawesome', {
        label: 'Insert Font Awesome Icon',
        command: 'fontawesome',
        icon: this.path + 'icons/fontawesome.png'
      });

      CKEDITOR.dialog.add('fontawesomeDialog', CKEDITOR.getUrl(this.path + 'dialogs/fontawesome.js'));
    }
  });

})();
