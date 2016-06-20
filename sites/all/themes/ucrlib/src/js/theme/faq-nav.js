(function($, Drupal) {

  "use strict";

  // In page nav for the FAQ page
  Drupal.behaviors.faqNav = {
    attach: function (context, settings) {

      if ($('.view-faqs').length) {
        var navItems = [];
        $('.view-faqs > .view-content > h3').each(function(idx, el) {
          var $el = $(el);
          var id = $el.text().toLowerCase().replace(/[^\w]/gi, '');
          $el.attr('id', 'faq-' + id);
          navItems.push('<a href="#faq-' + id + '" class="in-page">' + $el.text() + '</a>');
        });

        if (navItems.length > 0) {
          var nav = '<div class="faq__in-page-nav"><h3>Jump to:</h3><ul>';
          $.each(navItems, function(idx, item) {
            nav += '<li>' + item + '</li>';
          });
          nav += '</ul></div>';

          $('.view-faqs').prepend(nav);
        }

        $('a.in-page').on('click', function(event) {
          var target = $($(this).attr('href'));

          if (target.length) {
            event.preventDefault();
            $('html, body').animate({
              scrollTop: target.offset().top - 25
            }, 1000);
          }
        });
      }

    }
  };

})(jQuery, Drupal);
