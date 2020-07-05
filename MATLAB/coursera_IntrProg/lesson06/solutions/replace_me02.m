function w = replace_me(v,a,b,c)
    if nargin < 3
        b = 0;
    end
    if nargin < 4
        c = b;
    end
    w = v;                                      % make w the same as v
    wi = 1;                                     % wi is used to index into w
    for vi = 1:length(v)
        if v(vi) == a
            w = [w(1:wi-1) b c w(wi+1:end)];    % insert b and c at position wi
            wi = wi + 1;                        % increment wi
        end
        wi = wi + 1;                            % wi is incremented in either case
    end
end