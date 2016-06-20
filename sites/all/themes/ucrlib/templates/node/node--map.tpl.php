<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="map" id="map"></div>

</article>

<script src="https://maps.googleapis.com/maps/api/js"></script>
<script>
  function initialize() {

    var mapCanvas = document.getElementById('map');
    var myLatlng = new google.maps.LatLng(<?php print $latitude; ?>,<?php print $longitude; ?>);
    var mapOptions = {
      center: myLatlng,
      zoom: <?php print $zoom; ?>,
      mapTypeId: google.maps.MapTypeId.ROADMAP,
      disableDefaultUI: true
    }

    var map = new google.maps.Map(mapCanvas, mapOptions);

    var marker = new google.maps.Marker({
      position: myLatlng,
      map: map
    });
  }

  google.maps.event.addDomListener(window, 'load', initialize);
</script>
