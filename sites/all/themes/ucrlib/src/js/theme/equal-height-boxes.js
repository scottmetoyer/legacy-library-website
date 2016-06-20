(function($, Drupal) {

  "use strict";

  // Make boxes same height
  Drupal.behaviors.equalHeightBoxes = {
    attach: function (context, settings) {

      var items = [
        {
          parent: '.front .region-content',
          child: '.front .region-content > .block'
        },
        {
          parent: '.page-id-research-services .region-content',
          child: '.page-id-research-services .region-content > .block'
        }
      ];

      function setHeights() {
        $.each(items, function(idx, el) {
          if ($(el.child).length) {
            $(el.child).height('auto');

            var cWidth = $(el.child).width();
            var pWidth = $(el.parent).width();
            var percent = 100 * cWidth / pWidth;

            if (percent > 45 && percent <= 50) {
              var rows = Math.ceil($(el.child).length / 2);

              for (var i = 0; i < rows; i++) {
                var left = $(el.child).eq((2 * i));
                var right = $(el.child).eq((2 * i) + 1);
                var height = Math.max(left.height(), right.height());

                right.height(height);
                left.height(height);
              }
            }
            else if (percent > 30 && percent <= 35) {
              var rows = Math.ceil($(el.child).length / 3);

              for (var i = 0; i < rows; i++) {
                var left = $(el.child).eq((3 * i));
                var middle = $(el.child).eq((3 * i) + 1);
                var right = $(el.child).eq((3 * i) + 2);
                var height = Math.max(left.height(), middle.height(), right.height());

                right.height(height);
                middle.height(height);
                left.height(height);
              }
            }
          }
        });
      }

      setHeights();
      $(window).load(setHeights);
      $(window).resize(setHeights);

    }
  };

})(jQuery, Drupal);
