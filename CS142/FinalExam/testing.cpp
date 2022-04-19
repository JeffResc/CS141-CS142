#include<iostream>
#include<tgmath.h>

void mergeArrays(int arr[], int start, int middle, int stop, int fs) {
  int newArrLength = (stop - middle) + (middle - start);
  if (newArrLength > 1) {
    //std::cout << "-----" << std::endl;
    int *tmpNewArr = new int [newArrLength];
    int *newArr = new int [newArrLength];
    int j = 0;
    for(int i = start; i < middle; i++ && j++) {
      newArr[j] = tmpNewArr[i];
    }
    for(int i = middle; i < stop; i++ && j++) {
      newArr[j] = tmpNewArr[i];
    }
    while(j > 0) {
      int min = -1;
      // Find min and append to newArr until tmpNewArr is empty and
      // all values in tmpNewArr are in newArr, but sorted from min to max
    }
  }
  for(int i = 0; i < fs; i++) {
    if (i == start)
      std::cout << '[';
    else
      std::cout << ' ';
    if (i == middle)
      std::cout << "][";
    else
      std::cout << "  ";
    if (i == stop)
      std::cout << ']';
    else
      std::cout << ' ';
    std::cout << arr[i];
  }
  std::cout << std::endl;
}

void mergeSort(int arr[], int start, int stop, int fs) {
  if (start < stop) {
    int middle = floor((start + stop) / 2);
    mergeSort(arr, start, middle, fs);
    mergeSort(arr, middle + 1, stop, fs);
    mergeArrays(arr, start, middle, stop, fs);
  }
}

int main() {
  int arr[8] = {53, 62, 91, 15, 72, 48, 32, 27};
  mergeSort(arr, 0, (sizeof(arr) / sizeof(int)) - 1, (sizeof(arr) / sizeof(int)) - 1);
}
