function [ s1,s2,sums ] = sines( pts,amp,f1,f2 )

if nargin == 3
    f2  = f1 + (f1*0.05);    
elseif nargin == 2
    f1  = 100;
    f2  = f1 + (f1*0.05);    
elseif nargin == 1
    amp = 1;
    f1  = 100;
    f2  = f1 + (f1*0.05);
elseif nargin == 0
    pts = 1000;
    amp = 1;
    f1  = 100;
    f2  = f1 + (f1*0.05);
end

t = (0:pts-1)/(pts-1);
s1   = amp * sin( 2*pi*f1.*t );
s2   = amp * sin( 2*pi*f2.*t );
sums = s1 + s2;

end