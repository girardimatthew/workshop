function c = classify_v02(x)
    mindim = min(size(x));
    maxdim = max(size(x));
    if mindim == 0      % if one dim == 0, it must be empty
        c = -1;
    elseif maxdim == 1  % otherwise, both dim == 1 (since max == 1) -> scalar
        c = 0;
    elseif mindim == 1  % otherwise, if the smaller dim == 1 -> vector
        c = 1;
    else
        c = 2;
    end
end