function Vd = voldif(R,n)
%voldif
%   this function takes the radius R and the dimensionality n as input, 
%   and returns the difference between the volumes of 
%   the hypercube and hypersphere, Vd
%   
%   USAGE:
%   Vd = voldif(R, n)
%
%   INPUT
%   - R:        Radius (non-negative decimal number)
%   - n:        Dimensionality (positive integer)
%
%   OUTPUT
%   - Vd:       Difference between volume of hypercube 
%               and hypersphere (decimal number)
%
if R<0
    fprintf(2,'WARNING in voldif:\n\t R is negative: %d\n',R);
    return;
end
if n<0
    fprintf(2,'WARNING in voldif:\n\t n is negative: %d\n',n);
    return;
end
Vs = ((pi.^(n/2))/gamma(n/2+1))*(R.^n);
Vc = (2*R).^n;
Vd = Vc - Vs;
end