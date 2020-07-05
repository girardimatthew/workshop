% tricky code with no explicit loops

function s = square_wave02(n)
    t = 0 : 4*pi/1000 : 4*pi;   % setup vector according to the specs
    idx = (2*(1:n)' - 1);       % make column vector of fist n odd numbers (2k-1)
    % idx*t makes a matrix; each row is (2k-1)*t, for a given k
    % idx*ones(size(t)) also makes a matrix; each element of row k is just (2k-1)
    % sum down the columns
    s = sum(sin(idx*t) ./ (idx*ones(size(t))),1);
end

% the second argument to sum is needed in case n is 1
% remember that sum(x) sums x along columns unless x is a row vector!