(function ($) {
	Drupal.behaviors.idap_efq_carousel = {
		attach: function (context, settings) {
		
			$("#slides", context).slides({
					play:5000,
					hoverPause:true,
					pause:1,
					crossfade:true,
					fadeSpeed:1000
			});
		}	
	}
})(jQuery);
    
		
		
		

