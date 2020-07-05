function T = timeDilation(t, v)
%timeDilation
%   this function takes as input a vector of Nt values for the time on 
%   the spaceship (in seconds) as well as a vector of Nv values of the 
%   velocity (in meters/second) and computes a matrix of size Nt × Nv 
%   that contains the corresponding time (in seconds) on earth 
%   for each combination of the given times and velocities of the spaceship.
%   
%   USAGE:
%   function T = timeDilation(t, v)
%
%   INPUT
%   - t:            Time on spaceship, t (vektor)
%   - v:            Velocity of spaceship, v (vektor)
%
%   OUTPUT
%   - T:            Time on earth, T (matrix)
%
lenT = length(t);
lenV = length(v);
T = zeros(lenT,lenV);
c = 299792458;
for i = 1:lenT
    for j = 1:lenV
        T(i,j) = t(i)/sqrt(1-(v(j)^2/c^2));
    end
end
end