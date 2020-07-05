function k = derangements(n)
%derangements
%   this function takes as input the size of a set and computes as 
%   output the number of derangements according to the formula above.
%   
%   USAGE:
%   function k = derangements(n)
%
%   INPUT
%   - n:
%
%   OUTPUT
%   - k:
%
f = n;
for i = 1:n-1
    f = f*i;
end
k = round(f/exp(1));
end

% % function k = derangements(n)
% % % Compute the number of derangements
% % k = round(factorial(n) / exp(1));