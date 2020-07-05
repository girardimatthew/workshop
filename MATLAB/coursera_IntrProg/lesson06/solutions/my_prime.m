% using a for-loop

function a = my_prime(n)
    a = false;
    if n > 1                    % 1 is by definition not prime
        for ii = 2:sqrt(n)      % see explanation below
            if ~mod(n,ii)
                return;
            end
        end
        a = true;
    end
end
% x is prime if it is NOT divisible by all integers from 2 to sqrt(x)
% because factors have to come in pairs -- one bigger than sqrt(x) and
% one smaller (or both equal)