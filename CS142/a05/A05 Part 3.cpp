/*
  Jeffrey Rescignano <rescigjj@clarkson.edu>
  CS142 - Assignmenent 5 (Part 3)
  https://people.clarkson.edu/~alexis/CS142/Assignments/a05.pdf
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  /* replace() Demo
     Replaces 10 with 99 in vector v. */
  std::vector<int> v = {1, 5, 10};
  replace(v.begin(), v.end(), 10, 99);
  for (int x : v) {
    std::cout << x << std::endl;
  }
  /* std::max_element() Demo
     Finds greatest value in ints (will be 65). */
     int ints[] = {1,65,50};
  int element = *std::max_element(ints,ints+3);
  std::cout << element << std::endl;
}
