/*
  Jeffrey Rescignano <rescigjj@clarkson.edu>
  CS142 - Assignmenent 5 (Part 1)
  https://people.clarkson.edu/~alexis/CS142/Assignments/a05.pdf
*/

#include <iostream>
#include <vector>

void append(std::vector<int> & v1, std::vector<int> & v2) {
  // push_back each element of v2 into v1.
  for (int x : v2) {
    v1.push_back(x);
  }
}

int main() {
  // Define two vectors so that we may append one to the other.
  std::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {6, 7, 8, 9, 10};
  // Append v2 to the end of v1
  append(v1, v2);
  // std::cout v1 so we can test that the append worked.
  for (int x : v1) {
    std::cout << x << std::endl;
  }
  return 0;
}
