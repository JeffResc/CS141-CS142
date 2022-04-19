/*
  Jeffrey Rescignano <rescigjj@clarkson.edu>
  CS142 - Assignmenent 8, Part 1
  https://people.clarkson.edu/~alexis/CS142/Assignments/a08.pdf
*/

#include <iostream>
#include <vector>

template <typename T>
T* subarray(const T *a, int i, int m) {
  T * subArr = new T[m-1]{};
  for(int j = i; j < i+m-1; j++) {
    subArr[j] = a[j];
  }
  return subArr;
}

int main() {
  int intsArray[5] = {1,2,3,4,5};
  std::cout << subarray(intsArray, 1, 3) << std::endl;
}
