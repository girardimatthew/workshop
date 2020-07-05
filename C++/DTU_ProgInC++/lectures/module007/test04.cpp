#include <iostream>
#include "vector2d.h"
 
using namespace std;
 
static void printvec(v2d v) {
        static v2d x(1, 0);
        static v2d y(0, 1);
        cout << '(' << v*x << ',' << v*y << ')';
}
 
int main() {
     
    static const int N = 1000;
    static const double a[] = {-28,6,-14,-7,44,95,-72,-45,-84,34,72,6,80,-22,32,58,60,71,-78,-81,41,57,-64,58,-12,97,91,-83,-51,-52,95,-73,82,-87,47,-61,20,56,46,20,-15,-53,-86,-66,33,95,-18,-88,-77,26,-86,-59,90,44,-64,-13,97,94,-55,-8,23,57,65,80,-28,-20,-12,0,97,-46,-72,-16,-98,-85,-25,3,-45,-35,-37,-25,-31,-37,-94,1,17,-70,82,8,51,-59,9,75,-65,-81,71,-53,-41,-93,-16,75,58,73,-6,-18,-62,32,65,39,-75,70,-99,56,58,-94,34,-25,-37,69,-34,52,57,56,69,-33,92,-10,9,-45,-96,70,65,34,-47,-4,41,-68,-32,56,50,-85,77,8,-8,11,73,-37,-81,-2,41,5,87,41,-30,37,-93,55,3,-95,99,17,73,-64,35,-45,21,-27,30,-95,50,1,-60,-74,-85,10,41,-60,-95,3,-92,-76,10,33,52,98,-49,-27,-25,-94,-46,-15,-88,-30,-46,26,-59,58,-37,-4,7,49,-87,62,11,-59,88,-4,60,27,47,-57,-68,-71,-11,-86,37,74,-55,-79,12,83,-38,-9,-12,-67,72,70,-84,-4,-97,-9,-51,96,11,18,36,96,-82,-68,68,73,-28,85,6,-78,-69,34,-28,64,60,88,-24,20,-73,80,25,-54,89,-21,-32,14,62,21,29,-6,37,-32,71,81,-13,-90,33,98,90,36,-6,-92,-37,97,-50,17,97,-76,98,-14,-17,-29,85,0,-31,-49,22,-57,61,-41,-96,99,-64,-96,-9,-49,70,78,95,-58,-99,-86,15,-83,-68,6,85,-78,71,18,-61,-10,67,-45,84,-89,-31,29,-83,11,91,-91,14,-90,60,65,-53,-18,-97,21,-10,0,13,49,-12,63,-96,-69,36,-72,60,90,30,44,4,-9,-68,-28,-95,43,17,5,21,-5,65,-7,-5,-79,-30,-19,69,99,39,69,66,37,23,78,13,74,-66,57,52,66,42,25,59,-90,42,-66,-58,-16,75,-98,66,94,-18,39,74,37,2,-75,-19,-74,59,29,-99,-10,-45,-88,95,-17,-84,-29,-56,-82,74,32,81,-78,4,-44,-82,-48,-14,91,-65,86,46,-52,9,-58,58,-7,-46,34,71,-39,45,-60,-88,47,-96,-3,57,-81,68,-77,60,-5,82,24,15,-82,-49,-29,63,-67,-5,-70,-47,-53,-86,48,-36,67,88,-61,-68,88,62,-83,-50,16,35,-21,-88,69,7,18,63,-68,-39,12,74,45,79,-53,-51,-4,-22,17,-97,-91,49,30,16,-72,-78,-14,78,53,68,17,72,58,39,-99,36,-63,25,-65,58,-68,-94,-56,-10,-78,33,-56,-75,54,-90,36,22,1,42,76,-29,60,-65,93,71,4,-92,-7,-91,16,71,88,-86,-79,-68,37,81,24,-8,-19,61,44,2,-51,49,-78,72,-15,33,-95,60,-75,48,-32,25,-9,-47,29,-57,38,-49,-66,10,59,-60,-8,-21,-38,44,-22,51,14,25,-41,-91,-55,90,-60,-29,93,-93,-3,39,55,72,1,-39,26,87,30,37,-76,-37,35,25,-74,24,-60,-91,-21,-31,-27,50,73,-43,-85,-50,-64,-67,48,25,-41,12,75,53,1,-19,65,-5,65,-38,-29,-85,-29,58,69,-81,33,-30,49,-51,72,-73,-44,51,-15,4,-78,97,-25,-57,-51,-49,50,-1,-21,95,-66,63,-40,25,-1,-47,-65,-12,-2,47,31,8,83,-67,80,45,-16,-23,55,-91,67,-78,-55,67,57,88,-37,-71,28,44,-95,77,-95,72,-16,-28,-92,-75,-84,54,-33,-68,93,-56,57,-46,-15,91,-73,82,86,49,41,-68,40,-43,9,-72,-81,69,73,59,60,-2,76,-44,64,3,76,-27,13,13,-2,81,-17,-60,8,6,-3,86,-47,-72,-32,-99,-42,-5,54,-91,-6,77,13,86,8,65,20,86,-18,-74,-51,47,-48,58,-82,-78,88,53,0,-39,-96,-7,-35,-42,-7,12,-48,-87,-57,-14,15,-86,-75,61,26,-13,8,-67,79,-96,74,98,-95,-42,33,75,-38,15,-43,-96,14,7,-83,-76,-46,-3,-37,-4,39,48,-9,-18,-90,-7,88,66,19,75,0,-73,76,67,-58,12,-28,-26,67,69,43,67,58,-81,-40,-55,46,-82,81,20,-58,8,12,-56,60,57,-60,-10,60,59,-60,-42,-57,-8,76,-70,94,31,-1,7,-77,41,-64,44,-81,13,-35,76,-88,-31,98,29,-38,3,-16,-56,5,91,-13,-41,-93,-43,-60,-3,-3,96,-77,18,92,33,-9,-45,2,-17,67,-32,82,10,48,72,31,-71,86,85,-95,46,43,33,16,34,-44,8,64,93,52,-7,-51,65,80,-69,-91,32,-51,20,44,54,-46,-97,-99,22,-28,41,-44,70,60,-66,-36,5,-23,85,62,-67,52,-81,-77,0,-35,47,-99,62,-73,74,76,-94,-23,36,57,-71,84,97,-17,86,-15,-26,-61,32,-15,93,-11,-10,39,64,-97,57,56,-87,68,55,0,-23,32,13,34,44,-98,44,-24,-11,35,-51,55,-11,-91,46,45,-28,41,97,-85,56,-30,-32,-49,-41,-96,5,-42,-93,-64,-91,45,-65,55,64,40};
    static const double b[] = {67,88,54,-14,-15,-41,-75,85,88,23,5,26,-3,91,23,-85,-91,-39,87,-32,-49,14,17,-76,-67,35,-51,83,-35,-52,73,-24,15,-53,96,97,-86,60,5,-59,58,-4,-91,-78,-97,-8,46,59,-87,-95,91,49,85,40,-1,26,-85,-22,-47,3,-82,2,16,-36,-70,-97,-60,81,30,-73,-37,53,-6,30,86,76,-24,-38,-72,-77,-8,-1,-2,-9,-51,-18,-34,-44,69,-73,-93,-31,-8,37,-36,69,83,0,71,54,44,-61,-12,29,-26,25,72,-2,-61,26,40,73,-1,59,-38,-98,-96,-45,-27,68,51,26,53,71,-81,-82,-34,26,-45,59,-43,50,-30,-66,70,-36,96,-54,80,-28,-98,94,2,42,34,87,21,-50,89,77,-50,-71,77,-30,-29,-87,-30,-60,29,67,38,-56,52,51,-18,34,-65,87,92,57,-2,50,71,96,24,99,8,-82,99,59,67,89,-41,79,62,97,66,-52,86,-7,-22,48,-72,-20,50,22,-19,-40,-21,96,-83,-54,-85,-54,47,94,-85,74,83,52,83,57,-80,19,-51,72,-41,-58,-28,0,65,24,-26,23,-86,-37,-34,98,-62,-53,62,43,65,-83,-84,19,-58,2,83,48,50,-17,98,2,46,-75,-58,49,-94,-70,62,73,95,73,-1,-4,32,61,-59,63,11,36,70,19,58,58,90,-33,0,-33,13,-3,26,-13,52,-51,-9,-58,72,21,-85,97,-4,-31,-24,-7,-23,34,81,-54,-19,-71,63,26,62,-8,4,-36,59,60,71,97,-90,78,-36,1,68,59,63,75,-51,-2,6,96,-56,16,95,-76,-89,99,16,4,24,66,5,-94,53,81,35,-39,65,74,59,-64,7,-21,93,27,91,82,-77,-56,-56,-21,-92,65,-68,-3,-20,-48,-61,22,2,-46,49,-46,16,-35,-35,33,-32,14,98,-34,-95,-34,44,98,17,8,41,49,29,97,-85,22,75,-57,10,-40,-86,45,-85,28,1,-23,-21,-91,91,-28,40,13,-8,79,-91,57,49,-79,-17,-12,-67,-46,-60,60,77,1,-6,94,5,-1,47,53,55,-20,-10,92,-45,80,-2,24,20,-12,-32,-58,-65,-86,-78,84,68,-91,1,30,-16,42,-39,23,-58,71,45,55,89,-33,-67,0,87,83,44,71,-31,-22,71,66,21,5,23,10,89,83,-35,-11,-94,-67,8,54,91,61,-73,24,-5,26,-49,42,36,35,-78,17,-4,16,-35,51,-54,73,-47,90,53,26,-52,-44,-80,-58,21,56,-40,-67,89,-78,79,-89,28,60,4,13,-58,55,-77,84,57,90,53,-3,-91,57,86,5,-55,80,76,-76,92,43,13,78,-82,-12,47,-85,76,-9,-76,26,31,72,70,-67,57,-91,42,-42,5,10,-25,75,-85,-10,63,-5,-48,-81,65,-3,-82,60,-28,87,2,-36,82,69,56,0,13,-59,-22,53,-41,-54,16,7,-56,98,17,57,93,35,-84,-57,-37,-40,30,71,49,-46,8,9,-99,89,-48,37,45,47,72,80,17,-31,20,-71,59,45,-41,16,-88,24,3,-49,-90,-28,-69,-63,-61,-16,-46,-37,51,-20,12,63,-50,71,-36,-67,36,83,87,33,-93,45,13,-15,-1,-17,-41,-55,-10,-84,-69,47,77,6,-51,21,61,-40,-18,-40,21,38,-34,73,84,-80,68,-93,-24,-79,35,-74,2,40,-6,-99,-34,-82,-35,53,44,26,-92,34,-91,-57,82,66,0,-50,40,-3,-16,79,-86,24,-89,-26,13,2,-53,77,-87,-83,46,82,-38,42,78,-67,-86,73,87,79,-41,69,-19,-57,67,-29,-83,40,-42,68,54,20,-57,43,-31,-55,31,-71,-96,49,-41,-80,79,18,-43,-42,85,-27,-58,-74,-89,-9,99,-16,-88,-87,-15,57,36,-92,-86,71,-15,1,70,-25,-45,91,14,7,80,91,-6,-96,-30,-98,36,61,-84,69,-83,-25,97,64,6,84,-66,-59,79,53,-65,57,-37,-65,64,-53,88,-69,-85,43,15,18,-46,8,-19,61,7,31,-74,-4,13,52,-21,-89,-54,23,-13,-50,-27,87,-23,39,9,78,30,-69,53,35,-82,-12,-98,28,-21,61,-22,-11,-51,-1,-3,-5,27,68,17,-10,-40,-33,59,-10,-89,-96,-57,62,58,95,-70,-96,-95,-21,64,34,-86,-17,-15,83,74,22,21,-59,-75,-41,96,-70,-64,-31,-80,-22,-15,28,53,40,-33,44,63,-17,60,-20,77,32,-3,-28,0,-27,-14,67,-58,57,-20,-93,33,22,13,-15,39,78,35,51,-56,-80,-34,85,83,-89,83,-14,74,49,-71,-66,96,-10,-28,-43,87,71,-51,87,-82,72,95,-37,12,20,-30,-74,-87,-26,18,16,45,66,2,-79,-93,-47,-3,-3,40,-23,-5,-74,83,-17,-47,-15,-50,-84,-43,60,93,-53,86,-14,-27,42,-93,85,3,10,20,-52,37,-61,-98,-72,71,63,8,19,-97,36,17,-84,-62,-1,26,87,-26,35,-90,66,96,33,86,6,62,-88,74,-35,30,86,77,-34,49,-82,-72,56,-96,5,-62,47,97,51,28,-70,80,77,94,30,29,-18,-7,-84};
    static const double c[] =
    {-58,36,-29,86,-78,-66,53,77,82,23,-23,31,70,-69,69,29,-20,99,86,-41,-64,-76,24,1,38,-3,70,-39,28,21,89,62,-22,-68,20,40,-18,33,-87,66,97,84,-55,-17,-80,53,-20,-92,48,66,38,30,77,-62,64,-24,-51,-7,-83,-11,37,-91,65,-41,93,-7,16,-12,2,9,78,-88,8,-43,-54,-38,-89,-91,13,-50,-49,6,-90,-68,-79,26,46,74,9,-75,-2,80,5,-46,6,78,16,29,-96,50,-99,43,-58,-8,66,-79,-8,-36,-81,-70,67,-8,33,-50,61,31,-10,-35,-87,2,-28,-23,55,13,97,-36,-73,-44,-27,-77,5,15,86,-65,-97,-30,11,-89,-16,36,77,-45,-37,92,-87,-41,63,78,-90,6,-34,72,-79,33,59,38,-45,-51,65,-82,20,63,-64,-97,46,42,-8,-49,99,44,68,-23,-3,-87,76,39,-74,-90,33,34,-83,63,88,-53,0,-31,-72,94,-77,-56,-74,61,86,-65,-54,62,-73,-77,83,-6,-98,92,73,-9,21,-57,68,16,85,14,15,-74,96,30,10,61,-61,-71,29,-49,26,53,-77,-16,-67,-85,-32,85,70,-50,79,11,22,14,-98,-34,70,-52,-56,-2,96,91,38,68,-44,-63,91,90,36,-62,-22,-86,69,-46,-82,-55,92,73,33,70,-86,9,82,-43,1,-84,-74,59,45,-1,-92,-47,-18,75,13,7,-69,-28,-57,31,8,-86,-43,45,98,-62,8,50,82,-28,-27,90,45,38,-57,-16,43,41,92,-75,-39,-54,-86,24,57,12,-39,-6,90,-60,36,-45,-55,-1,-91,46,-45,-91,-30,70,39,-71,-67,-81,26,-65,54,4,2,0,-81,97,-38,88,71,86,26,-46,66,36,-4,-46,-73,-74,76,-18,-30,39,81,-41,45,98,-9,47,69,97,78,-41,-15,-23,-33,17,81,-55,-69,-86,-43,-67,-63,30,72,-67,73,-25,25,-4,-87,-87,72,-71,-6,-95,12,-87,-21,63,-15,5,-66,-81,27,7,-47,90,-33,-23,96,53,79,-79,64,98,94,-88,-39,29,-93,10,-41,-34,35,-63,-64,57,-21,-18,10,59,15,32,-37,15,-30,-34,-63,95,-41,9,-61,45,20,-59,-54,21,30,31,-22,65,-50,9,-90,1,-66,31,-51,-73,59,11,57,-13,-30,66,98,26,86,-53,-21,97,-61,30,-75,20,-32,-19,92,25,99,-7,59,41,38,-39,-62,-51,50,-43,-52,-64,-46,23,50,94,-68,68,76,78,40,14,-1,89,92,-88,-85,85,-80,-55,-76,-73,50,31,59,47,61,-9,-13,42,-6,29,15,70,-88,-13,-2,17,-85,-96,2,28,88,-36,86,96,-85,13,-57,44,-88,-73,70,61,61,80,-96,-11,-40,24,49,97,6,68,-53,32,12,-14,-69,87,-59,-28,-86,83,-57,-13,98,90,74,9,-28,14,71,92,-51,67,42,4,-80,99,-47,-18,-42,-90,25,-84,-4,-77,75,-78,23,-44,-4,-71,-60,22,65,43,24,-35,13,15,-54,10,-28,7,-64,-31,95,85,-40,-25,62,-85,-18,-17,-7,40,73,89,98,54,-74,-61,-95,-77,-96,76,4,61,-45,94,2,-34,-72,-35,-58,87,-89,-65,79,-2,-87,97,84,-48,84,53,28,-40,67,49,0,-5,55,-51,48,56,-32,-9,93,50,-71,31,-31,-15,32,-46,-61,38,-17,40,-3,3,-39,55,-66,64,77,93,-61,-78,66,57,49,-74,-34,1,70,-10,-12,-78,-76,-21,-61,24,61,59,-89,-4,11,98,-29,-67,-71,66,-63,18,69,-83,28,-27,81,-62,-70,5,60,-90,95,-43,-97,-3,-54,-58,-29,-19,88,-28,-79,-69,-12,-93,-20,55,-2,-8,-88,-89,61,41,-9,-87,-1,27,3,27,28,18,-11,-82,-72,27,-32,-52,-12,-82,-62,-53,-87,84,-82,-28,-80,84,81,-69,17,83,-34,-24,-97,-71,78,-37,-50,-74,31,24,-97,-49,-89,63,19,87,26,-16,-77,-90,-34,44,-55,7,-13,-17,41,-69,14,5,61,-71,61,88,80,-92,85,-16,23,-33,-61,73,-27,96,28,-74,44,-66,30,54,14,-77,-55,-81,-73,-50,-37,60,2,-65,-40,80,18,-96,93,66,16,41,-45,85,93,6,91,-75,17,4,-20,-77,-82,-74,58,-25,58,50,41,59,-94,-68,-58,-2,-46,51,83,-48,-71,82,15,17,-76,-74,5,48,-42,-85,-4,-4,41,6,-61,-10,28,56,-18,34,92,-3,15,36,30,-65,-4,-51,-2,98,69,13,77,-17,-63,24,74,94,-94,-5,-73,-67,9,46,-72,-70,-3,-93,-95,91,-81,57,-85,10,74,-13,26,-59,-97,60,55,22,18,84,6,-1,30,80,94,-32,-57,-2,-66,53,-21,-97,85,-4,6,34,45,23,-67,59,-8,-49,-1,36,-43,-89,99,-53,-61,78,64,56,67,69,-63,96,-88,45,-36,-81,43,-8,-34,-95,85,66,-69,38,-34,-85,-58,47,28,-29,63,75,-40,-21,86,-87,-92,-71,13,-23,12,11,-89,-57,81,-53,14,-65,-42,99,-18,-43,-87,5,-92,-23,20,-84,67,-24,-11,17,-89,33};
     
     
    cout << "Testing on " << N << " vectors\n";
     
    cout << "\nMultiplying the vectors with scalars\n";
    for(int i = 0; i < N; i++) {
        v2d v(a[i], b[i]);
        printvec(v);
        cout << '*' << c[i] << '=';
        v * c[i];
        printvec(v);
        cout << '\n';
    }
     
    cout << "\nSumming over the vectors\n";
    v2d sum(0,0);
    for(int i = 0; i < N; i++) {
        v2d v(a[i], b[i]);
        printvec(sum);
        cout << '+';
        printvec(v);
        sum + v;
        cout << '=';
        printvec(sum);
        cout << '\n';
    }
     
    cout << "\nTaking their dot product\n";
    for(int i = 0; i < N - 1; i++) {
        v2d v1(a[i], b[i]);
        v2d v2(a[i+1], b[i+1]);
        printvec(v1);
        cout << '*';
        printvec(v2);
        cout << '=' << v1 *  v2 << '\n';
    }
     
    cout << "\nCalculating their lengths\n";
    for(int i = 0; i < N; i++) {
        v2d v(a[i], b[i]);
        cout << "length";
        printvec(v);
        cout << '=' << v.length();
        cout << '\n';
    }
 
}