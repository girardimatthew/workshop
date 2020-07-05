% ([1 2 3], 2, 4, 5) works fine
% ([1 2 3], 2, 5) works fine
% ([1 2 3], 4, 5, 6) works fine
% ([1 2 3 4 5], 6) works fine
% ([1 2 3 4 5 6 7 8 9 10], 2, 2) doesn't work fine !
function result = replace_me3(v,a,b,c)
    if nargin == 3
        c = b;
    end
    if nargin == 2
        b = 0;
        c = 0;
    end
    result = v;
    rep = sum(result == a);

    if rep == 0
     return
    end

    for ii = 1:(length(result) + rep)
        if result(ii) == a
            result = [result(1:ii-1), [b c], result(ii+1:end)];
            ii = ii + 2;
        end
    end
end