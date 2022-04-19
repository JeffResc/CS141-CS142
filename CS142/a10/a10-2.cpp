/*
  Jeffrey Rescignano <rescigjj@clarkson.edu>
  CS142 - Assignmenent 10, Part 2
  https://people.clarkson.edu/~alexis/CS142/Assignments/a10.pdf
*/

#include<iostream>

struct SearchArray {
  int *arr;
  int *origStart;
  int *start;
  int *origEnd;
  int *end;
  int searchingFor;
  int middle;
  int idx = -1;
};

void binarySearch(SearchArray & SA) {
  SA.origStart = SA.start;
  SA.origEnd = SA.end;
  SA.middle = (SA.end-SA.start)/2;

  while((SA.end-SA.start) > 1) {
    for(int i = 0; i <= (SA.origEnd-SA.origStart); i++) {
      if (SA.arr[i] == *SA.start) {
        std::cout << '[';
      } else {
        std::cout << ' ';
      }
      std::cout << SA.arr[i];
      if (SA.arr[i] == *SA.end) {
        std::cout << ']';
      } else {
        std::cout << ' ';
      }
    }
    std::cout << " | Middle: "<< SA.arr[SA.middle] << std::endl;

    /*std::cout << "start: " << *SA.start << std::endl;
    std::cout << "end: " << *SA.end << std::endl;
    std::cout << "Middle: " << SA.middle << std::endl;*/

    if (SA.searchingFor == SA.arr[SA.middle]) {
      SA.idx = SA.middle;
      for(int i = 0; i <= (SA.origEnd-SA.origStart); i++) {
        if (SA.arr[SA.middle] == SA.arr[i]) {
          std::cout << '[' << SA.arr[i] << ']';
        } else {
          std::cout << ' ' << SA.arr[i] << ' ';
        }
      }
      std::cout << " | Found: "<< SA.arr[SA.middle] << std::endl;
      break;
    } else if (SA.searchingFor < SA.arr[SA.middle]) {
      //std::cout << "Changing End from " << *SA.end << " to " << SA.arr[SA.middle] << std::endl;
      SA.end = &SA.arr[SA.middle];
    } else {
      //std::cout << "Changing Start from " << *SA.start << " to " << SA.arr[SA.middle] << std::endl;
      SA.start = &SA.arr[SA.middle];
    }
    if (SA.middle != (SA.end-SA.start)/2) {
      SA.middle = (SA.end-SA.start)/2;
    } else {
      break;
    }
  }
  std::cout << std::endl << "-----" << std::endl << std::endl;
  if (SA.idx != -1) {
    std::cout << "Found number at middle: " << SA.arr[SA.middle] << std::endl;
    std::cout << "Found at index: " << SA.idx << std::endl;
  } else {
    std::cout << "Could not find " << SA.searchingFor << " in arr" << std::endl;
  }
  std::cout << std::endl << "-----" << std::endl;
}

int main() {
  int origArr[8] = {11, 27, 28, 30, 36, 42, 58, 65};
  SearchArray SA;
  SA.arr = origArr;
  SA.start = &origArr[0];
  SA.end = &origArr[7];
  SA.searchingFor = 27;
  binarySearch(SA);

  int origArr2[8] = {11, 27, 28, 30, 36, 42, 58, 65};
  SearchArray SA2;
  SA2.arr = origArr2;
  SA2.start = &origArr2[0];
  SA2.end = &origArr2[7];
  SA2.searchingFor = 50;
  binarySearch(SA2);
}
