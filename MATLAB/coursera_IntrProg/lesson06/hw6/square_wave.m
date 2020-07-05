function rvect = square_wave(n)
k = 1;
sqrw = 0;
pts = 1001;
t = ((0:pts-1)/(pts-1).*4.*pi);
while k <= n
    sqrw = sqrw + sin((2.*k-1).*t)./(2.*k-1);
    k = k+1;
end
rvect = sqrw;
end

%(sin((2.*k-1).*t)./(2.*k-1))