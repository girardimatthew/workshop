#include "VecN.h"
#include <algorithm>
#include <iostream>

using namespace std;

VecN::VecN(int * v, int size){
	_size=max(1,size);
	array=new int[_size];
	for (int i = 0; i<_size; ++i) {
		array[i] = v[i];
	}
};

void VecN::printVecN() {
	for (int i = 0; i<_size; ++i) {
		cout << array[i] << " ";
	}
	cout << endl;
};

int VecN::dotProduct(const VecN & a) {
	int dot = 0;
	for (int i = 0; i<_size; ++i) {
		dot += array[i] * a.array[i];
	}
	return dot;
}

void VecN::vectSum(const VecN & a) {
	for (int i = 0; i<_size; ++i) {
		cout << array[i] + a.array[i] << " ";
	}
	cout << endl;
}

// vecN::vecN(const vecN & v){
//   _size=v._size;
//   capacity=v.capacity;
//   array=new int[capacity];
//   for(int i=0; i<_size; i++)
//     array[i]=v.array[i];
//   std::cout << "Copy Constructor called\n";  
// };

VecN::~VecN(){
  // std::cout << "Destructor called\n";
  delete [] array;
};

// vecN & vecN::operator=(const vecN & v){
//   if (&v != this){
//     delete [] array;
//     _size=v._size;
//     capacity=v.capacity;
//     array=new int[capacity];
//     for(int i=0; i<_size; i++)
//       array[i]=v.array[i];
//   }
//   return *this;
// };


// int & vecN::operator[](int i){
//   //if (i>=size()) throw 42;
//   return  array[i];
// };
// void vecN::push_back(int v){
//   if (_size>=capacity){
//     capacity=capacity*2;
//     std::cout << "capacity increased to " << capacity << "\n";
//     int * tmp=new int[capacity];
//     for(int i=0; i<_size; i++){
//       tmp[i]=array[i];
//     }
//     delete [] array;
//     array=tmp;
//   }
//   array[_size++]=v;
// };
// int vecN::size(){
//   return _size;
// };
