/*
  Jeffrey Rescignano <rescigjj@clarkson.edu>
  CS142 - Assignmenent 10, Part 1
  https://people.clarkson.edu/~alexis/CS142/Assignments/a10.pdf
*/

#include<vector>
#include<iostream>
#include<iterator>

template <typename Iterator, typename T>
int sequentialSearch(Iterator start, Iterator stop, T e) {
  for (Iterator itr = start; itr != stop; itr++) {
    if (*itr == e) return itr-start;
  }
  return -1;
}

int main() {
  std::vector<std::string> v;
  std::cout << "Enter 5 variables to use in the vector:" << std::endl;
  for(int i = 0; i < 5; i++) {
    std::string addStr;
    std::cin >> addStr;
    v.push_back(addStr);
  }
  std::cout << "Enter the variable to search for:" << std::endl;
  std::string findStr;
  std::cin >> findStr;
  int idx = sequentialSearch(v.begin(), v.end(), findStr);
  if (idx == -1) {
    std::cout << "Could not find variable in vector" << std::endl;
  } else {
    std::cout << "Variable found at index " << idx << std::endl;
   }
}
