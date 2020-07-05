function ysmooth = movingAvg(y)
% signal vector as input and computes the five-sample weighted moving average of the signal.
% INPUT
% y         : Input signal (vector)
% OUTPUT
% ysmooth   : Five-sample moving average smoothing of input signal (vector)

tic;
yL = length(y);
v1 = [1 2 3 2 1];
sV = sum(v1);
if yL < 2
    ysmooth = y*3/sV;
else
    yMtrx = [y(3:end), zeros(1,2); 
    y(2:end),zeros(1,1); 
    y; 
    zeros(1,1), y(1:end-1); 
    zeros(1,2), y(1:end-2)];
    ysmooth = (v1*yMtrx)/sV;
end
toc;
end

%% Suggested solution
% tic;
% % Returns the 5-sample symmetric weighted moving average of the
% % input vector, computed as
% % ysmooth(i) = (y(i-2) + 2*y(i-1) + 3*y(i) + 2*y(i+1) + y(i+2)) / 9
%  
% % Length of input vector
% N = length(y);
%  
% % Weights
% w = [1, 2, 3, 2, 1];
%  
% % Signal matrix with two extra columns at beginning and end
% M = zeros(5, N + 4);
%  
% % Fill in rows with weighted signal
% for i = 1:5
%     M(i, i-1 + (1:N)) = w(i) * y;
% end
%  
% % Cut the two extra columns at beginning and end
% M = M(:, 2 + (1:N));
%  
% % Compute moving average
% ysmooth = sum(M, 1) / 9;
% toc;