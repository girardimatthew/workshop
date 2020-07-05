% ([1 2 3 4 5 2], 2, 4, 5) doesn't work fine
function result = replace_me2(v,a,b,c)
    if nargin == 3
        c = b;
    end
    if nargin == 2
        b = 0;
        c = 0;
    end
    result = [];
    for ii = 1:length(v)
        if isequal(v(ii),a)
            result = horzcat(v(1:ii-1), [b c], v(ii+1:end));
        end
    end
end