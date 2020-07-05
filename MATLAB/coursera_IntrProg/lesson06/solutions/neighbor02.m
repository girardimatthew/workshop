function w = neighbor02(v)
    if length(v) < 2 || min(size(v)) ~= 1  % must be a vector of at least two elements
        w = [];
    else
        w = abs(v(1:end-1)-v(2:end));      % take the difference of two subvectors
    end                                    % of length (n-1)
end