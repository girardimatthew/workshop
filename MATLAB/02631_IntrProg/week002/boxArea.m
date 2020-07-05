function A = boxArea(bxcr, area)
assert(length(bxcr)==8);
assert(min(bxcr)>=0)
assert(strcmp(area,'Box1') | strcmp(area,'Box2') | strcmp(area,'Intersection') | strcmp(area,'Union'));
% Use a switch statement to choose between the different areas to compute.
switch area
   case  'Box1'
      % compute area of box one
      A = (bxcr(2)-bxcr(1))*(bxcr(6)-bxcr(5));
      
   case  'Box2'
      % compute area of box two
      A = (bxcr(4)-bxcr(3))*(bxcr(8)-bxcr(7));
   case  'Intersection'
      % compute area of intersection
      A = max(0,min(bxcr(2),bxcr(4)) - max(bxcr(1),bxcr(3))) * max(0,min(bxcr(6),bxcr(8)) - max(bxcr(5),bxcr(7)));
   case  'Union'
      % Insert code to compute area of union
      A1 = (bxcr(2)-bxcr(1))*(bxcr(6)-bxcr(5));
      A2 = (bxcr(4)-bxcr(3))*(bxcr(8)-bxcr(7));
      A3 = max(0,min(bxcr(2),bxcr(4)) - max(bxcr(1),bxcr(3))) * max(0,min(bxcr(6),bxcr(8)) - max(bxcr(5),bxcr(7)));
      A = A1+A2-A3;
end