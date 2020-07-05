function conf = confidence(x)
%confidence
%   this function takes a vector x as input and returns 
%   the lower and upper confidence interval bounds as 
%   a vector conf of length two
%   
%   USAGE:
%   conf = confidence(x)
%
%   INPUT
%   - x:        Observations (vector of decimal numbers)
%
%   OUTPUT
%   - conf:     Lower and upper confidence bounds (vector of length 2)
%
conf = zeros(1,2);
n = length(x);
m = mean(x);
sdev = std(x);
conf(1) = m - (2*(sdev/sqrt(n)));
conf(2) = m + (2*(sdev/sqrt(n)));
end