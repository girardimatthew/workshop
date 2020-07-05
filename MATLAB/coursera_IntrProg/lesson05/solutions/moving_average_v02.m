% Using no if-statement

function avg = moving_average_v02(in)
    persistent buffer;
    buffer = [in buffer(1:end-(length(buffer) == 25))];
    avg = mean(buffer);
end

% This is an illustration of a short, but tricky solution. However,
% a longer, but more readable solution is always preferred, therefore,
% the first solution is better!
%
% This one works by realizing that we do not need to check whether the
% buffer is empty or not, since [x buffer] will work either way.
% The tricky part is how the length is handled. While the buffer is
% shorter than 25, buffer(1:end) is used. Once it reaches 25, it turns
% into buffer(1:end-1), exactly what is needed.