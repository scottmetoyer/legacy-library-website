// Our dialog definition.
CKEDITOR.dialog.add('fontawesomeDialog', function(editor) {
  return {
    // Basic properties of the dialog window: title, minimum size.
    title: 'Insert Font Awesome Icon',
    minWidth: 400,
    minHeight: 200,

    // Dialog window content definition.
    contents: [{
        // Definition of the Basic Settings dialog tab (page).
        id: 'tab-default',
        label: 'Basic Settings',

        // The tab content.
        elements: [{
          // Text input field for the icon code.
          type: 'text',
          id: 'faicon',
          label: 'Font Awesome Code (ex. fa-birthday-cake)',

          // Validation checking whether the field is not empty.
          validate: CKEDITOR.dialog.validate.notEmpty("Font Awesome Code field cannot be empty."),

          // Called by the main setupContent method call on dialog initialization.
          setup: function(element) {
            var classes = element.getAttribute('class');
            var faClass = classes.split('fa ').join('').trim();
            this.setValue(faClass);
          },

          // Called by the main commitContent method call on dialog confirmation.
          commit: function(element) {
            element.removeAttribute('class');
            element.addClass('fa ' + this.getValue());
          }
        }]
      }
    ],

    // Invoked when the dialog is loaded.
    onShow: function() {

      // Get the selection from the editor.
      var selection = editor.getSelection();

      // Get the element at the start of the selection.
      var element = selection.getStartElement();

      // Get the <span> element closest to the selection, if it exists.
      if (element) {
        element = element.getAscendant('span', true);
      }

      // Create a new <span> element if it does not exist.
      if (!element || element.getName() != 'span') {
        element = editor.document.createElement('span');

        // Flag the insertion mode for later use.
        this.insertMode = true;
      }
      else {
        this.insertMode = false;
      }

      // Store the reference to the <span> element in an internal property, for later use.
      this.element = element;

      // Invoke the setup methods of all dialog window elements, so they can load the element attributes.
      if (!this.insertMode) {
        this.setupContent(this.element);
      }
    },

    // This method is invoked once a user clicks the OK button, confirming the dialog.
    onOk: function() {

      // The context of this function is the dialog object itself.
      // http://docs.ckeditor.com/#!/api/CKEDITOR.dialog
      var dialog = this;

      // Create a new <span> element.
      var icon = this.element;

      // Invoke the commit methods of all dialog window elements, so the <span> element gets modified.
      this.commitContent(icon);

      // Finally, if in insert mode, insert the element into the editor at the caret position.
      if (this.insertMode)
        editor.insertElement(icon);
    }
  };
});
