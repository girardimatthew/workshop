function y = lowpass(x, dt, RC)

% Return RC low-pass filter output samples, given input samples,
% time interval dt, and time constant RC

y = zeros(length(x)+1,1);
alpha = dt / (RC + dt);
for i = 2 : length(x)
   y(i) = alpha * x(i) + (1-alpha) * y(i-1);
end
end