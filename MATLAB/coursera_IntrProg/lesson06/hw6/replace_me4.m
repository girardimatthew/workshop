% Bugged
function result = replace_me4(v,a,b,c)
    if nargin == 3
        c = b;
    end
    if nargin == 2
        b = 0;
        c = 0;
    end
    rep = sum(v == a);

    if rep == 0
        result = v;
        return; 
    end

    result = zeros(1, length(v) + rep);
    
    idx = 1;
    for ii = 1:length(v)
       if v(ii) == a
           result(idx) = b;
           result(idx+1) = c;
           idx = idx + 2;
       else 
           result(idx) = a;
          idx = idx + 1;
       end
    end
end