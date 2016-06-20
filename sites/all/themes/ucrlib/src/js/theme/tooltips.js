(function($, Drupal) {

  "use strict";

  // Convert labels to placeholders
  Drupal.behaviors.tooltips = {
    attach: function (context, settings) {

      var items = [
        '.database__require-logged-in',
        '.database__trial-database'
      ];

      $.each(items, function(idx, el) {
        if ($(el).length) {
          $(el).tooltip({
            position: {
              my: 'center bottom-20',
              at: 'center top',
              using: function(position, feedback) {
                $(this).css(position);
                $('<div>')
                  .addClass('arrow')
                  .appendTo(this);
              }
            }
          });
        }
      });

    }
  };

})(jQuery, Drupal);
