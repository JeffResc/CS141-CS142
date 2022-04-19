/*
  Jeffrey Rescignano <rescigjj@clarkson.edu>
  CS142 - Assignmenent 6
  https://people.clarkson.edu/~alexis/CS142/Assignments/a06.pdf
*/

#include<iostream>
#include<vector>
#include<iterator>
#include<ostream>

// Used in Parts 1 & 2
template <typename Iterator>
void printIt(Iterator start, Iterator stop) {
  for (Iterator itr = start; itr != stop; itr++) {
    std::cout << *itr << ' ';
  }
  std::cout << std::endl;
  return;
}

// Part 1
template <typename Iterator>
void increment(Iterator start, Iterator stop, int x) {
  for (Iterator itr = start; itr != stop; itr++) {
    *itr = *itr + x;
  }
  return;
}

// Part 2
template <typename InitList>
int total(InitList init_list) {
  int total = 0;
  for (auto itr = init_list.begin(); itr != init_list.end(); itr++) {
    total += *itr;
  }
  return total;
}

// Part 3
template <typename Iterator, class UnaryPredicate>
void print_if(Iterator start, Iterator stop, UnaryPredicate condition, std::ostream & out) {
  for (Iterator itr = start; itr != stop; itr++) {
    if (condition(*itr))
      out << *itr << std::endl;
  }
  return;
}

// Condition function for part three
inline bool stringIsLargerThanThreeChars(const std::string & str) {
    return str.length() > 3 ? true : false;
}

int main() {
  // Used in Parts 1 & 2
  std::vector<int> sampleVector = { 1, 2, 3, 4, 5 };
  std::vector<int>::iterator beginIterator = sampleVector.begin();
  std::vector<int>::iterator endIterator = sampleVector.end();

  // Part 1
  std::cout << "Part 1" << std::endl << "----------" << std::endl;
  int numToAdd = 10;
  increment(beginIterator, endIterator, numToAdd);
  printIt(beginIterator, endIterator); // 11 12 13 14 15
  std::cout << std::endl;

  // Part 2
  std::cout << "Part 2" << std::endl << "----------" << std::endl;
  std::cout << total(sampleVector) << std::endl; // 11 + 12 + 13 + 14 + 15 = 65
  std::cout << std::endl;

  // Part 3
  std::cout << "Part 3" << std::endl << "----------" << std::endl;
  std::vector<std::string> vectorOfStrings = { "This", "is", "a", "vector", "of", "strings" };
  print_if(vectorOfStrings.begin(), vectorOfStrings.end(), stringIsLargerThanThreeChars, std::cout);
}
