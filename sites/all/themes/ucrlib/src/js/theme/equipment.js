(function($, Drupal) {

  "use strict";

  // Show/hide equipment term info on equipment view.
  Drupal.behaviors.equipmentView = {
    attach: function(context, settings) {

      if ($('.view-equipment').length) {

        //
        // Show the taxonomy term
        var tid = parseInt(getUrlParameter('type'), 10);
        if ($.isNumeric(tid)) {
          $('.equipment-term-id-' + tid).show();
        }


        //
        // Collapse the term list to only show the top 5 terms (plus the 'all').
        var isTermsOpen = false;
        $('#edit-type-wrapper').append('<a class="equipment-type-list-toggle" href="#">Show more</a>');

        $('.equipment-type-list-toggle').click(function() {
          if ($(this).hasClass('expanded')) {
            collapseTermList(isTermsOpen);
          }
          else {
            expandTermList(isTermsOpen);
          }
        });

        adjustTermList(isTermsOpen);
        $(window).resize(function() {
          adjustTermList(isTermsOpen);
        });
      }

    }
  };

  function adjustTermList(isTermsOpen) {
    if (!isTermsOpen) {
      collapseTermList();
    }
  }

  function collapseTermList(isTermsOpen) {
    var firstSix = $('#edit-type .form-item').slice(0, 6);
    var firstSixHeight = 0;
    $.each(firstSix, function(idx, el) {
      firstSixHeight += $(el).outerHeight(true);
    });

    $('#edit-type').animate({
        height: firstSixHeight
      }, 250, function() {
        $('.equipment-type-list-toggle').text('Show more').removeClass('expanded');
        isTermsOpen = false;
      }
    );
  }

  function expandTermList(isTermsOpen) {
    var allHeight = 0;
    $.each($('#edit-type .form-item'), function(idx, el) {
      allHeight += $(el).outerHeight(true);
    });

    $('#edit-type').animate({
        height: allHeight
      }, 250, function() {
        $('.equipment-type-list-toggle').text('Show less').addClass('expanded');
        isTermsOpen = true;
      }
    );
  }

  function getUrlParameter(sParam) {
    var sPageURL = window.location.search.substring(1);
    var sURLVariables = sPageURL.split('&');
    for (var i = 0; i < sURLVariables.length; i++) {
      var sParameterName = sURLVariables[i].split('=');
      if (sParameterName[0] == sParam) {
        return sParameterName[1];
      }
    }
  }

})(jQuery, Drupal);
