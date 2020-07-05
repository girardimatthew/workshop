function n = carsAvailable(fleet, category)
%carsAvailable
%   this function takes a vector containing the number of cars 
%   available and a string representing one of the categories 
%   and returns the number of cars available in that category. 
%   The function must compare only the first character of the 
%   given category string and must be insensitive to case. 
%   If the requested category for example is s, Stnd, or st the function 
%   must return the number of cars in the Standard category. 
%   If the requested category does not match the first character 
%   of any of the 6 categories, the function must return ?1 (negative one).
%   
%   USAGE:
%   n = carsAvailable(fleet, category)
%
%   INPUT
%   - fleet:
%   - category
%
%   OUTPUT
%   - n:
%
cat = upper(category(1));
if cat == 'M'
    n = fleet(1);
elseif cat == 'E'
    n = fleet(2);
elseif cat == 'C'
    n = fleet(3);
elseif cat == 'S'
    n = fleet(4);
elseif cat == 'F'
    n = fleet(5);
elseif cat == 'L'
    n = fleet(6);
else
    n = -1;
end
end
