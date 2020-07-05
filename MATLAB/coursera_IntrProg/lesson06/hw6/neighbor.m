function out = neighbor(v)
out = [];
    if isvector(v)
        if length(v) >= 2
            for ii = 1:length(v)-1
                out = abs([out v(ii) - v(ii+1)]);
            end
        else
            out = [];
        end        
    end
end