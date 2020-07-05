function w = neighbor(v)
    w = [];
    if min(size(v)) == 1                    % must be a vector
        for ii = 1:length(v)-1              % if length is less than 2, loop won't do anything
            w(ii) = abs(v(ii+1) - v(ii));
        end
    end
end