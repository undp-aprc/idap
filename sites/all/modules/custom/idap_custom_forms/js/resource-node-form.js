(function ($) {

  Drupal.behaviors.idap_custom_forms = {
	attach: function (context, settings) {
		
		$('#tabs', context).tabs();
		
	}	
}

})(jQuery);