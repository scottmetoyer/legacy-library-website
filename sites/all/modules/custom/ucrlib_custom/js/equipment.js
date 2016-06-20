/**
 * 
 */
(function($, Drupal) {

  "use strict";

  // Build the exposed filter items for the Equipment view.
  Drupal.behaviors.equipmentExposedFilter = {
    attach: function (context, settings) {

      if ($('#equipment-filter-nid').length) {

        // Create a checkbox for each library.
        var checkboxes = [];
        checkboxes.push('<div id="equipment-filter-checkboxes" class="equipment-filter-checkboxes">');
        $.each(settings.ucrlibCustom.equipmentViewLibraries, function(idx, el) {
          checkboxes.push(
            '<div class="form-item form-type-checkbox form-item-type">',
              '<input type="checkbox" id="edit-nid-' + el.nid + '" value="' + el.nid + '">',
              '<label class="option" for="edit-nid-' + el.nid + '">' + el.title + '</label>',
            '</div>'
          );
        });
        checkboxes.push('</div>');
        $('#equipment-filter-nid').closest('form').after(checkboxes.join(''));

        // Check the boxes upon page load.
        var existingNids = $('#equipment-filter-nid').val().split(',');
        $.each(existingNids, function(idx, el) {
          $('#edit-nid-' + el).prop('checked', 'checked');
        });

        // Handle the checkboxes, and submit the form.
        $('#equipment-filter-checkboxes input').click(function() {
          var nid = $(this).val() + '';
          var nids = $('#equipment-filter-nid').val().split(',');

          if ($(this).prop('checked')) {
            // Add the nid of it's not already present.
            if ($.inArray(nid, nids) == -1) {
              nids.push(nid);
            }
          }
          else {
            // Remove the nid if it is already present.
            if ($.inArray(nid, nids) >= 0) {
              nids = $.grep(nids, function(val) {
                return val !== nid;
              });
            }
          }

          var newNids = nids.join(',');
          newNids = (newNids.length && newNids[0] == ',') ? newNids.slice(1) : newNids;
          $('#equipment-filter-nid').val(newNids);
          $('#edit-submit-equipment').click();
        });
      }

    }
  };

})(jQuery, Drupal);
