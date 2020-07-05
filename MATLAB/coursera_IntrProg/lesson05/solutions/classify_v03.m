% Using no if-statements
function y = classify_v03 (x)
    d = size(x);
    p = prod(d);                        % multiplies the two dims
    y = -1 +(p>=1) +(p>1) +(min(d)>1);   % each added condition increases the answer by one
end

% Note that the first two solutions are longer but easier to read and understand than this one.