/*
  Jeffrey Rescignano <rescigjj@clarkson.edu>
  CS142 - Assignmenent 7, Part 1
  https://people.clarkson.edu/~alexis/CS142/Assignments/a07.pdf
*/

#include<string>
#include<iostream>
#include<algorithm>
#include<vector>

class StartsWith {
  char c;
public:
  StartsWith(const char & c) : c(c) {};
  inline bool operator()(const std::string & s) const {
    return (s[0] == c);
  }
};

int main() {
  const char testChar = 'a';
  std::vector<std::string> v = {"alice", "bob", "alex", "joe", "carole", "alexis"};
  int count = std::count_if(v.begin(), v.end(), StartsWith(testChar));
  std::cout << "v contains " << count  << " names that start with " << testChar << ".\n";

  return 0;
}
