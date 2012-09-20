
(function ($)
{
	$.fn.blockUserRegionWidth = function (options)
	{
		var maxWidth = 0; //Store the size of the widest block in a user-block-region
		
		return this.each(function(){
	      var obj=$(this);
	        objWidth = obj.find('.block').width();
	
			if (objWidth > maxWidth) {
				maxWidth = objWidth;
			}
			
			obj.width(maxWidth);
		});
	};
})(jQuery);