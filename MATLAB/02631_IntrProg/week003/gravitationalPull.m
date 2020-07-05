function g = gravitationalPull(x)
% Computes the gravitational pull in meters per second squared at a
% distance x to the center of the earth

% Radius of earth
R = 6.371e6;

% Gravitational pull at surface
g0 = 9.82;

% Compute gravitational pull
if isvector(x)
    % Make empty vector to store result
    g = zeros(1, length(x));
    % Compute gravitational pull for x < R
    g(x < R) = g0 * x(x < R) / R;
    % Compute gravitational pull for x >= R
    g(x >= R) = g0 * R^2 ./ x(x >= R).^2;
else 
    if x < R
        g = g0*(x/R);
    else 
        g = g0*((R^2)/(x^2));
    end
end