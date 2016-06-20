(function($, Drupal) {

  "use strict";

  // Simple tabbed content
  Drupal.behaviors.simpleTabs = {
    attach: function (context, settings) {

      var triggers = [
        '.collection__body-tabs-tab a'
      ];
      var wrappers = [
        '.collection__body-tabs'
      ];
      var targets = [
        '.collection__body-tabs-pane'
      ];

      // Initialize the content
      $.each($(triggers), function(idx, val) {
        $(val).addClass('st-trigger').first().addClass('active');
      });
      $.each($(targets), function(idx, val) {
        $(val).addClass('st-target').first().addClass('active');
      });
      $.each($(wrappers), function(idx, val) {
        $(val).addClass('st-wrapper');
      });

      $('a.st-trigger').click(function() {
        var $this = $(this);
        if ($this.hasClass('active')) {
          return false;
        }
        else {
          var id = $this.data('st-trigger');
          var target = '.st-target[data-st-target="' + id + '"]';
          $this.closest('.st-wrapper').find('.st-trigger').removeClass('active');
          $this.closest('.st-wrapper').find('.st-target').removeClass('active');
          $this.addClass('active');
          $this.closest('.st-wrapper').find(target).addClass('active');
        }
        return false;
      });

    }
  };

})(jQuery, Drupal);

(function($, Drupal) {

  "use strict";

  // Simple tabbed content
  Drupal.behaviors.equalHeightTabs = {
    attach: function (context, settings) {

      function setHeight() {
        var tabHeight = 0;
        $('#quicktabs-collections_subject_areas .quicktabs-tabs li a').each(function(idx, el) {
          $(el).height('auto');
          var $elHeight = $(el).height();
          if ($elHeight > tabHeight) {
            tabHeight = $elHeight;
          }
        });
        $('#quicktabs-collections_subject_areas .quicktabs-tabs li a').height(tabHeight);
      }

      // setHeight();
      // window.onresize = setHeight;

    }
  };

})(jQuery, Drupal);
