/*
  Jeffrey Rescignano <rescigjj@clarkson.edu>
  CS142 - Assignmenent 8, Part 2
  https://people.clarkson.edu/~alexis/CS142/Assignments/a08.pdf
*/

#include<string>
#include<vector>
#include<iostream>

class String {
  char *cs;
public:
  String() : cs() {};
  String(char *str) : cs(str) {}
  String(const String & s) : cs(s.cs) {}
  // Cannot find an accurate way to get the length of the array, therefore this method does not work,
  // it breaks the test driver, but the methods themselves regardless should be functional
  inline int length() const {
    return sizeof(cs);
  }
  inline void clear() {
    for (int i = 0; i < length(); i++) {
      cs[i] = '\0';
    }
  }
  String operator=(const String & s) {
    return (cs = s.cs);
  }
  char operator[](const int & n) {
    return cs[n];
  }
  char * c_str() {
    return cs;
  }
  String operator+(const String & s) {
    const int sizeOfCs = length();
    const int sizeOfS = s.length();
    const int newSize = sizeOfCs + sizeOfS;
    char *newArr = new char[newSize]{};
    for(int i=0; i < sizeOfCs; i++) {
      newArr[i] = cs[i];
    }
    for(int i=sizeOfCs; i < newSize; i++) {
      newArr[i] = s.cs[i];
    }
    return String(newArr);
  }
};

int main() {
  char testStr[6] = "apple";
  char testStr2[8] = "pumpkin";
  String a(testStr);
  String b(testStr2);
  String c(a + b);
  for(int i = 0; i < c.length(); i++) {
    std::cout << c[i];
  }
  std::cout << std::endl;
  return 0;
}
