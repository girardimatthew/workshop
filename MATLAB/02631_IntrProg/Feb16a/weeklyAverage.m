function weekTemp = weeklyAverage(dayTemp)
%weeklyAverage
%   this function takes as input a vector containing 7 temperature 
%   measurements and returns the average when the 
%   two highest and the two lowest temperatures are excluded.
%   
%   USAGE:
%   weekTemp = weeklyAverage(dayTemp)
%
%   INPUT
%   - dayTemp:              Temperature measurements (vector of length 7).
%
%   OUTPUT
%   - weekTemp:             Average temperature.
%
dayTemp = sort(dayTemp);
weekTemp = mean(dayTemp(3:end-2));
end
    
