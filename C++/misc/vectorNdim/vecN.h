#ifndef __VecN__
#define __VecN__

class VecN{
 private:
  int *array;
  int _size;
  int capacity;

 public:
  VecN(int * v, int size);
  void printVecN();
  int dotProduct(const VecN & a);
  void vectSum(const VecN & a);
  // vecN(const vecN & v);
  ~VecN();
  // vec & operator=(const vecN & v);
  // int & operator[](int i);
  // void push_back(int v);
  // int size();
};




#endif 
