% this function computes an estimate of the 
% square root of its input argument x

function y = approx_sqrt(x)
    y = x;
    % while abs(y^2 - x) > 0.001*x
    while abs(y^2 - x) > 1e-7*x
        y = (x/y + y)/2;
    end
end