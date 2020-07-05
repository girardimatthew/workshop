function bestValues = nBest(allValues, N)
%nBest
%   this function takes as input a vector of length K and an integer N, 
%   and returns a vector containing the N largest values from the original 
%   vector in the same order as they appear. You may assume that all 
%   the values are unique (no duplicates)
%   
%   USAGE:
%   bestValues = nBest(allValues, N)
%
%   INPUT
%   - allValues:            Matching scores (vector of decimal numbers)
%   - N:                    Number of products to recommend (positive integer).
%
%   OUTPUT
%   - bestValues:           N best matching scores (vector of decimal numbers).
%
sAllV = sort(allValues);
nElem = sAllV(end-(N-1):end);
idx = find(allValues >= nElem(1));
bestValues = allValues(idx);
end

% % % Sort the values in the array
% % sortedValues = sort(allValues, 'descend');
% %  
% % % Get the value of the Nth largest
% % NthLargest = sortedValues(N);
% %  
% % % Return the N largest values
% % bestValues = allValues(allValues >= NthLargest);