(function($, Drupal) {

  "use strict";

  // Image carousel
  Drupal.behaviors.imageCarousel = {
    attach: function (context, settings) {

      var carousels = [
        '.exhibit__carousel .item-list ul',
        '.page__carousel .item-list ul',
        '.subject-guide__carousel .item-list ul'
      ];

      $(carousels).each(function() {
        $(this).bxSlider({
          captions: true,
          pager: false
        });
      });

    }
  };

})(jQuery, Drupal);
