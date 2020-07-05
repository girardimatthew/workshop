#include <algorithm> // for std::swap, use <utility> instead if C++11
#include <iostream>

using namespace std;

void printArray(const int *array, int length) {
  for (int index = 0; index < length; ++index) {
    cout << array[index] << " ";
  }
}

void sortArray(int *array, int length) {
  // Step through each element of the array
  for (int startIndex = 0; startIndex < length; ++startIndex) {
    // smallestIndex is the index of the smallest element we've encountered so far.
    int smallestIndex = startIndex;
    // Look for smallest element remaining in the array (starting at startIndex+1)
    for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex) {
        // If the current element is smaller than our previously found smallest
        if (array[currentIndex] < array[smallestIndex])
          // This is the new smallest number for this iteration
          smallestIndex = currentIndex;
    }
    // Swap our start element with our smallest element
    swap(array[startIndex], array[smallestIndex]);
  }
}



int main() {
  const int length = 5;
  int array[length] = { 30, 50, 20, 10, 40 };
  // Now print our array
  printArray(array, length);
  cout << endl;
  sortArray(array, length);
  // Now print our sorted array as proof it works
  printArray(array, length);
  cout << endl;
  return 0;
}
