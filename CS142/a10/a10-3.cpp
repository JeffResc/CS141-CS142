/*
  Jeffrey Rescignano <rescigjj@clarkson.edu>
  CS142 - Assignmenent 10, Part 3
  https://people.clarkson.edu/~alexis/CS142/Assignments/a10.pdf
*/

/*
  Status Report:

  This program is a little broken. It currently sorts in reverse and the last
  number does not get sorted for some reason. I'm not sure how to fix it and
  it is running close to the submission deadline so I'm going to leave it how
  it is for now.
*/

#include <iostream>

struct SearchArray {
  int *arr;
  int *origStart;
  int *start;
  int *origEnd;
  int *end;
  int workingIndex;
};

void selectionSort(SearchArray SA) {
  SA.origStart = SA.start;
  SA.origEnd = SA.end;
  SA.workingIndex = SA.origEnd-SA.origStart;
  bool recordLargest;
  int largest;
  int idx;
  while(SA.workingIndex >= 0) {
    largest = -1;
    recordLargest = true;
    for(int i = 0; i <= SA.origEnd-SA.origStart; i++) {
      if (i == 0) {
        std::cout << '[';
      } else {
        std::cout << ' ';
      }
      std::cout << SA.arr[i];
      if (i == SA.workingIndex) {
        std::cout << ']';
        recordLargest = false;
      } else {
        std::cout << ' ';
      }
      if (recordLargest) {
        if (SA.arr[i] > largest) {
          largest = SA.arr[i];
          idx = i;
        }
      }
    }
    std::cout << "| Largest: " << largest << std::endl;
    for(int i = idx; i < SA.origEnd-SA.origStart; i++) {
      SA.arr[i] = SA.arr[i+1];
    }
    SA.arr[SA.origEnd-SA.origStart] = largest;
    SA.workingIndex--;
  }
}

int main() {
  int origArr[7] = {34, 12, 53, 92, 61, 17, 20};
  SearchArray SA;
  SA.arr = origArr;
  SA.start = &origArr[0];
  SA.end = &origArr[6];
  selectionSort(SA);
}
