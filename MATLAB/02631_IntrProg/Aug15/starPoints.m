function points = starPoints(a, b, maxArea)
%starPoints
%   this function computes the maximum number of points for a star 
%   with the given values of a and b such that the area of the 
%   star does not exceed the specified maximum area
%   
%   USAGE:
%   points = starPoints(a, b, maxArea)
%
%   INPUT
%   - a:                Distance from center to outer vertices (positive decimal number)
%   - b:                Distance from center to inner vertices (positive decimal number)
%   - maxArea:          The maximum area of the star (positive decimal number)
%
%   OUTPUT
%   - points:           Number of points on the star (integer)
%
n = 3;
currArea = n * a * b * sin(pi/n);
while currArea < maxArea
    n = n+1;
    currArea = n * a * b * sin(pi/n);
end
points = n-1;