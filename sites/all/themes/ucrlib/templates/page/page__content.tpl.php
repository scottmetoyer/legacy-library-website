<?php if (isset($outer_title) && $outer_title && isset($title) && $title) : ?>
  <div class="page-title__wrapper">
    <div class="l-general">
      <h1 class="title--page"><?php print $title; ?></h1>
    </div>
  </div>
<?php endif; ?>


<?php if (isset($page['content_prefix'])) : ?>
  <div class="main-content-prefix__wrapper">
    <div class="l-general">
      <?php print render($page['content_prefix']); ?>
    </div>
  </div>
<?php endif; ?>


<div class="main-content__wrapper">
  <div class="l-general">


    <?php if ($page['sidebar_first'] && $page['sidebar_second']) : ?>

      <div class="main-content__wrapper-inner">
        <?php if (isset($inner_title) && $inner_title && isset($title) && $title) : ?>
          <div class="page-title__wrapper">
            <h1 class="title--page"><?php print $title; ?></h1>
          </div>
        <?php endif; ?>

        <div class="main-content">
          <?php print render($page['content']); ?>
        </div>

        <aside class="sidebar--second">
          <?php print render($page['sidebar_second']); ?>
        </aside>
      </div>

      <aside class="sidebar--first">
        <?php print render($page['sidebar_first']); ?>
      </aside>

    <?php elseif ($page['sidebar_first']) : ?>

      <div class="main-content__wrapper-inner">
        <?php if (isset($inner_title) && $inner_title && isset($title) && $title) : ?>
          <div class="page-title__wrapper">
            <h1 class="title--page"><?php print $title; ?></h1>
          </div>
        <?php endif; ?>

        <div class="main-content">
          <?php print render($page['content']); ?>
        </div>
      </div>

      <aside class="sidebar--first">
        <?php print render($page['sidebar_first']); ?>
      </aside>

    <?php elseif ($page['sidebar_second']) : ?>

      <div class="main-content__wrapper-inner">
        <?php if (isset($inner_title) && $inner_title && isset($title) && $title) : ?>
          <div class="page-title__wrapper">
            <h1 class="title--page"><?php print $title; ?></h1>
          </div>
        <?php endif; ?>

        <div class="main-content">
          <?php print render($page['content']); ?>
        </div>

        <aside class="sidebar--second">
          <?php print render($page['sidebar_second']); ?>
        </aside>
      </div>

    <?php else : ?>

      <div class="main-content__wrapper-inner">
        <?php if (isset($inner_title) && $inner_title && isset($title) && $title) : ?>
          <div class="page-title__wrapper">
            <h1 class="title--page"><?php print $title; ?></h1>
          </div>
        <?php endif; ?>

        <div class="main-content">
          <?php print render($page['content']); ?>
        </div>
      </div>

    <?php endif; ?>


  </div>
</div>
