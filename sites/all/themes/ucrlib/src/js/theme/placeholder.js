(function($, Drupal) {

  "use strict";

  // Convert labels to placeholders
  Drupal.behaviors.labelToPlaceholder = {
    attach: function (context, settings) {

      var items = [
        {
          wrapper: '.view-database__filters-block #views-exposed-form-databases-page-1',
          label:   '.view-database__filters-block #edit-search-wrapper label',
          input:   '.view-database__filters-block #edit-search'
        }
      ];

      $.each(items, function(idx, el) {
        var text = $(el.label).text();
        $(el.label).hide();
        $(el.input).attr('placeholder', text.trim());
        $(el.wrapper).addClass('placeholderized');
      });

    }
  };

})(jQuery, Drupal);
