function t = thermoEquilibrium(N, r)
% INPUT
%   N : Initial number of gas particles in the left chamber (even integer number)
%   r : Sequence of random numbers (vector of decimal numbers between 0 and 1)
% OUTPUT
%   t : Time-steps used to reach equilibrium (integer number) Return zero if equilibrium is not reached.
Nl = N;
Nr = 0;
t = 0;
while Nl~=Nr
    t = t + 1;
    if t > length(r)
        t = 0;
        break;
    end
    pLR = Nl/N;
    if r(t) <= pLR
        Nr = Nr + 1;
        Nl = Nl - 1;
    else
        Nr = Nr - 1;
        Nl = Nl + 1;
    end
end
    