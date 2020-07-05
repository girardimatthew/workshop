function y = symmetrize(x)
%weekday
%   this function takes a quadratic matrix x as input 
%   and returns a symmetrized matrix y computed 
%   according to the algorithm above
%   
%   USAGE:
%   y = symmetrize(x)
%
%   INPUT
%   - x:        Matrix to be symmetrized (quadratix matrix)
%
%   OUTPUT
%   - v:        Symmetrized matrix (symmetric matrix)
%
s = size(x);
if s(1)~=s(2)
    fprintf(2,'Error in symmetrize\n\tInput matrix is not quadratic!\n');
    return;
end
y = zeros(s);

for i = 1:length(x)
    for j = 1:length(x)
        if i==j
            y(i,j) = x(i,j);
        else
            y(i,j) = x(i,j) + x(j,i);
        end
    end
end
end