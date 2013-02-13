(function ($) {
	Drupal.behaviors.idap_subscription_links = {
		attach: function (context) {
			$('.unsubscribe-link').click(function() {
				$('#overlay').css('display','block');
				$('.black-overlay').css('display','block');
				$('.white-content').css('display','block');
			});
		}
	}
})(jQuery);