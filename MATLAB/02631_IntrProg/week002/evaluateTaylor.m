% evaluate the Taylor series approximation 
% in Equation 2.1
% y = (x-1)-0.5(x-1)^2+0.3333(x-1)^2
function y = evaluateTaylor(x)
y = (x-1)-(1/2)*((x-1).^2)+(1/3)*((x-1).^3);
end

