// A function named getIndexOfLargestValue() that takes an integer array (as a pointer)
// and an array size, and returns the index of the largest element in the array.

#include <iostream>

using namespace std;

const int SIZE = 8;

int getIndexOfLargestValue(const int *array, int length) {
  int maxItem = 0;
  int at = 0;
  for (int i=0; i<length; ++i) {
    if (array[i] >= maxItem) {
      maxItem = array[i];
      at = i;
    }
  }
  return at;
};

void print_arr(const int *array, int n) {
  // if user passed in a null pointer for array, bail out early!
  if (!array)
    return;
  for (int i=0; i<n; ++i) {
    cout << i << ". " << array[i] << endl;
  }
};

int main() {
  int array[SIZE] = {2, 5, 9, 22, 42, 11, 0, 12};

  print_arr(array,SIZE);
  int index = getIndexOfLargestValue(array, SIZE);
  cout << "Largest elem at index at: " << index << endl;
}
