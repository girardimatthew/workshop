// *********************************************************************************
// Programming in C++ 
// Exercise 002
// module 003
// Matteo Girardi
// *********************************************************************************
// Random Walk
// *********************************************************************************

#include <iostream>
using namespace std;

const char moveleft='l';
const char moveright='r';
const char moveup='u';
const char movedown='d';
const char quit='q';

typedef enum {wood , stone} material;

typedef struct{
  int x,y;
  bool isWall;
  material type;
}field;

#define n 12
#define m 16
int x(5);
int y(5);
field playground[n][m];

field display() {
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if(playground[i][j].isWall) cout << "*";
			else if (i==y && j==x && !(playground[i][j].isWall)) cout << "O";
			else cout << " ";
			if (j==m-1) {cout << endl;}
		}
	}
	// just checking...
	// cout << "---------------------------------\n";
	// for (int i=0; i<n; i++) {
	// 	for (int j=0; j<m; j++) {
	// 		cout << i << j;
	// 		if (playground[i][j].isWall) cout << "* ";
	// 		else cout << "  ";
	// 		if (j==m-1) cout << endl;
	// 	}
	// }
};

int main(){
  	for (int i=0; i<n; i++){
  		for (int j=0; j<m; j++){
    		playground[i][j].x=i;
    		playground[i][j].y=j;
    		playground[i][j].isWall=((i==0 && j!=3) || i==(n-1) || (j==0 && i>0) || j==(m-1));
    		if (playground[i][j].isWall && !(i==3 && j==0))
    			playground [i][j].type=stone;
    		else
    			playground [i][j].type=wood;
    	}
    }

  	// input from the user
  	char move=' ';
  	display();
  	while (move!=quit) {
  		cin >> move;
  		switch (move) {
  			case quit:
  				break;
  			case moveleft:
  				if (!(playground[y][x-1].isWall)) {
  					--x;
  					display();
  				}
  				else 
  					display();
  				break;
  			case moveright:
  				if (!(playground[y][x+1].isWall)) {
  					++x;
  					display();
  				}
  				else 
  					display();
  				break;
  			case moveup:
  				if (y-1>=0 && !(playground[y-1][x].isWall)) {
  					--y;
  					display();
  				}
  				else 
  					display();
  				break;
  			case movedown:
  				if (!(playground[y+1][x].isWall)) {
  					++y;
  					display();
  				}
  				else 
  					display();
  				break;
  		}

  		// just checking...
  		// cout << "x:" << x << ", y:" << y << endl;
  		// cout << "y+1:" << playground[y+1][x].isWall << endl;
  		// cout << "y-1:" << playground[y-1][x].isWall << endl;
  		// cout << "x+1:" << playground[y][x+1].isWall << endl;
  		// cout << "x-1:" << playground[y][x-1].isWall << endl;
  	}
}