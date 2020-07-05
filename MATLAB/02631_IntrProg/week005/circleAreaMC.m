function A = circleAreaMC(xvals, yvals)
% estimates the area of a circle by Monte Carlo simulation
% INPUT 
%   xvals   : The x-coordinates of points (vector of decimal numbers)
%   yvals   : The y-coordinates of points (vector of decimal numbers) 
% OUTPUT
%   A       : Estimated value for the area of the circle (scalar decimal number)
As = 4;
n = 0;
for i = 1:length(xvals)
    mag = norm([xvals(i),yvals(i)]);
    if mag < 1
        n = n + 1;
    end
end
A = As * (n/length(xvals));
end

%% Suggested solution
% function A = circleAreaMC(xvals, yvals)
% % Estimates the area of a circle using Monte carlo estimation
%  
% % Compute the number of points
% N = length(xvals);
%  
% % Compute distance from each point to (0,0)
% dist = sqrt(xvals.^2 + yvals.^2);
%  
% % Count number of points inside the circle
% n = sum(dist < 1);
%  
% % Compute are of circle
% A = 4 * n / N;