function categoryName = climbCategorization(distance, grade)
%nearestColor
%   this function takes the distance and grade as input and 
%   returns the categorization of the climb as a string
%
%   USAGE:
%   colorName = nearestColor(r, g, b)
%
%   INPUT
%   - distance:             Distance in kilometers (decimal number)
%   - grade:                Grade in percent (decimal number)
%
%   OUTPUT
%   - categoryName:         Name of categorization of mountain climb (string)
%
categories = {'Beginner','Easy','Medium','Difficult','Extreme'};
if ( distance<2 || grade<1 || distance*grade<16 )
   categoryName = categories{1};
elseif ( distance<4 || grade<2 || distance*grade<32 )
   categoryName = categories{2};
elseif ( distance<8 || grade<4 || distance*grade<64 )
   categoryName = categories{3};
elseif ( distance<12 || grade<6 || distance*grade<96 )
   categoryName = categories{4};
else
   categoryName = categories{5};
end
end