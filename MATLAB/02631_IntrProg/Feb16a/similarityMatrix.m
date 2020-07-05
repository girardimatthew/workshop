function S = similarityMatrix(x, y, delta)
%similarityMatrix
%   this function takes as input the two vectors x and y as well 
%   as the length scale ? 'delta' and returns the similarity matrix S.
%   
%   USAGE:
%   S = similarityMatrix(x, y, delta)
%
%   INPUT
%   - x:                    Input data (vectors)
%   - y:                    Input data (vectors)
%   - delta:                Length scale (decimal number)
%
%   OUTPUT
%   - S:                    Similarity Matrix
%
sX = length(x);
sY = length(y);
S = zeros(sX,sY);
for i = 1:sX
    for j = 1:sY
        S(i,j) = exp(-delta*(x(i)-y(j))^2);
    end
end
end