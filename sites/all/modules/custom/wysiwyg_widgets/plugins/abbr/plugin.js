(function() {

  // Register the plugin
  CKEDITOR.plugins.add('abbr', {
    init: function(editor) {

      // Define an editor command that opens our dialog window.
      editor.addCommand('abbr', new CKEDITOR.dialogCommand('abbrDialog'));

      // Create a toolbar button that executes the above command.
      editor.ui.addButton('wysiwyg-widget-abbr', {
        label: 'Insert Abbreviation',
        command: 'abbr',
        icon: this.path + 'icons/abbr.png'
      });

      if (editor.contextMenu) {
        editor.addMenuGroup('abbrGroup');
        editor.addMenuItem('abbrItem', {
          label: 'Edit Abbreviation',
          icon: this.path + 'icons/abbr.png',
          command: 'abbr',
          group: 'abbrGroup'
        });

        editor.contextMenu.addListener(function(element) {
          if (element.getAscendant('abbr', true)) {
            return {
              abbrItem: CKEDITOR.TRISTATE_OFF
            };
          }
        });
      }


      CKEDITOR.dialog.add('abbrDialog', CKEDITOR.getUrl(this.path + 'dialogs/abbr.js'));
    }
  });

})();
