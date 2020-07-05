%% Example 
% this is not what you do in MATLAB. 
% this is waht you do on common programming languages.

w = [];
jj = 0;
for ii = 1:length(v)
    if v(ii) >= 0
        jj = jj + 1;
        w(jj) = v(jj);
    end
end