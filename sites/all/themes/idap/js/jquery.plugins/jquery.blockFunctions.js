(function ($)
{
	$.fn.blockFunctions = function (options)
	{
		var cumulativeBlockWidth = 0;
		var defaultSingleBlockWidth = 246;
		var rowCount = 1;
		
		return this.each(function(){
	      var obj=$(this);
			
			// Check the position of the block and add a class to indicate which column it is located in
			parentPosLeft = $(this).closest('#content').position(); //Get position for #content container at current window size
			thisPosLeft = $(this).position(); //Get position for this element at current window size
			thisRelativePos = parentPosLeft.left - thisPosLeft.left; //Position inside #content container
			thisColPos = Math.round(thisRelativePos / defaultSingleBlockWidth);
			$(this).addClass('colPos-'+thisColPos); //Add calculated colPos-x class to element (dimensions specified in stylesheet)
			
			// Check the width of the block and its parent then indicate which row it is in
			thisBlockWidth = obj.width(); //Store width of current block
			parentWidth = $(this).parent().width();
	      	cumulativeBlockWidth = cumulativeBlockWidth + thisBlockWidth; //Add to cumulative width
	
			if ((cumulativeBlockWidth / parentWidth) > 1) {
				cumulativeBlockWidth = thisBlockWidth;
				rowCount++;
			}
			
			thisColPos = cumulativeBlockWidth / defaultSingleBlockWidth;
			
			$(this).addClass('rowNum-'+rowCount);
			
	     });
	};
})(jQuery);