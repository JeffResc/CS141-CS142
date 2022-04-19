/*
  Jeffrey Rescignano <rescigjj@clarkson.edu>
  CS142 - Assignmenent 7, Part 2
  https://people.clarkson.edu/~alexis/CS142/Assignments/a07.pdf
*/

#include<string>
#include<iostream>
#include<vector>

template <typename List>
void print(const List & ls, int n) {
  if (n > ls.size())
    n = ls.size();
  for (auto itr = ls.begin(); itr != ls.begin()+n; itr++) {
    std::cout << *itr << std::endl;
  }
}

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5};

  print(v, 3); // Print first three elements
  print(v, 15); // Prints first fifteen elements, which will only print five as that is the vector size

  return 0;
}
