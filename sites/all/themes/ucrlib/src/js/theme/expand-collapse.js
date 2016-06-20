(function($, Drupal) {

  "use strict";

  // FAQ accordion
  Drupal.behaviors.expandCollapseLinks = {
    attach: function (context, settings) {

      var ecTriggers = [
        '.node-faq .faq__title',
        '.sidebar-first-nav .nav-item--level-2.expanded > .nav-link--level-2'
      ];
      var ecWrappers = [
        '.node-faq',
        '.sidebar-first-nav .nav-item--level-2.expanded'
      ];
      var ecTargets = [
        '.node-faq .faq__body',
        '.sidebar-first-nav .nav-item--level-2.expanded > ul.nav'
      ];

      // Insert the trigger into the dom
      $('<a href="#" class="ec-trigger collapsed">Expand</a>').appendTo($(ecTriggers));
      $.each($(ecWrappers), function(idx, val) {
        $(val).addClass('ec-wrapper');
      });
      $.each($(ecTargets), function(idx, val) {
        $(val).addClass('ec-target').hide();
      });

      // Expand active trail menus
      $.each($(ecWrappers), function(idxOuter, valOuter) {
        $.each($(valOuter), function(idxInner, valInner) {
          if ($(valInner).hasClass('active-trail')) {
            $(valInner).find('.ec-target').show();
          }
        });
      });

      $('a.ec-trigger').click(function() {
        var $this = $(this);
        if ($this.hasClass('expanded')) {
          $this.closest('.ec-wrapper').find('.ec-target').slideUp(500, function() {
            $this.text('Expand').addClass('collapsed').removeClass('expanded');
          });
        }
        else {
          $this.closest('.ec-wrapper').find('.ec-target').slideDown(500, function() {
            $this.text('Collapse').addClass('expanded').removeClass('collapsed');
          });
        }
        return false;
      });

    }
  };

})(jQuery, Drupal);
