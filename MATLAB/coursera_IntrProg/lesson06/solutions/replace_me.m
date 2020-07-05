function w = replace_me(v,a,b,c)
    if nargin < 3
        b = 0;
    end
    if nargin < 4
        c = b;
    end
    w = [];
    for k = 1:length(v);
        if v(k) == a        % if a is found,
            w = [w,b,c];    % we insert b and c at the end of the current w
        else                % otherwise,
            w = [w,v(k)];   % we insert the original element of v
        end
    end
end