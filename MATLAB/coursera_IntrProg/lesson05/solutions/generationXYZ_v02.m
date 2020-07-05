% Using no if-statements
function gen = generationXYZ_v02(yr)
    opts = {'O','X','Y','Z','K'};  % Create cell array of options
    idx = 1 + sum(yr >= [1966,1981,2000,2013]); % Calculate index by comparing year to edge values
    gen = opts{idx};
end