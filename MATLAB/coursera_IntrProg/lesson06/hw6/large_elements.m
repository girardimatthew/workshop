function out = large_elements(X)
    [row, col] = size(X);
    out = [];
    for rr = 1:row
        for cc = 1:col
            s = rr+cc;
            if s < X(rr,cc)
                out = [out; rr,cc];
            elseif s > X(rr,cc)
                out  = [out; []];
            end
        end
    end
end