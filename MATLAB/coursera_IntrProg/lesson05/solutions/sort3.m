% Using no built-in function
function v = sort3(a, b, c)
    if a <= b
        v = [a b];
    else
        v = [b a];
    end
    if c >= v(2)            % a and b in v are ordered. Where to insert c?
        v = [v c];          % at the end
    elseif c <= v(1)
        v = [c v];          % at the beginning
    else
        v = [v(1) c v(2)];  % in the middle
    end
end