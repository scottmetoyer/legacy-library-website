(function($, Drupal) {

  "use strict";

  // Create a mobile nav using the SlickNav library
  Drupal.behaviors.mobileNav = {
    attach: function (context, settings) {

      $('.header__wrapper').once('mobilenav', function() {

        $('.region-hidden .main-nav .menu-block-wrapper > .nav').slicknav({
          prependTo: '.header__wrapper',
          allowParentLinks: true
        });

        // Wait momentarily before adding items to the mobile menu
        function timeout() {
          if ($('.slicknav_nav').length) {
            var search = $('<li class="search-form">')
              .prepend(
                $('#block-views-exp-search-page-page-1').clone()
                  .removeClass('search--header')
                  .addClass('search--mobile-nav')
              );
            $('.slicknav_nav').prepend(search);
            $('.search--mobile-nav').find('.form-text').attr('placeholder', 'Search...');

            var utility = $('<li class="utility-menu">')
              .prepend(
                $('#block-menu-menu-utility').clone()
                  .removeClass('utility-nav--header')
                  .addClass('utility-nav--mobile-nav')
              );
            $('.slicknav_nav').append(utility);
          }
          else {
            setTimeout(function () {
              timeout();
            }, 500);
          }
        }

        timeout();

      });

    }
  };

})(jQuery, Drupal);
