function c = speedOfLight(f, wavelengths)
%weeklyAverage
%   this function takes as input the frequency and a vector of 
%   measured wavelengths. The function must compute the speed of light 
%   for each wavelength according to the formula above, 
%   and return the average of the computed values..
%   
%   USAGE:
%   c = speedOfLight(f, wavelengths)
%
%   INPUT
%   - f:                    Frequency in Hz
%   - wavelengths:          Wavelengths in meters (vector)
%
%   OUTPUT
%   - c:                    Estimated speed of light
%
c = mean(f*wavelengths);
end