%% Example 
% This is what you do in MATLAB

w = []; % set w equals to an empty vector;
for ii = 1:length(v)
    if v(ii) >= 0
        w = [w v(ii)];
        % we are appending v(ii) to the end of w
    end
end
