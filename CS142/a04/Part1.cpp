#include<iostream>
#include<string>

std::string spaceString(const std::string & str) {
  std::string result;
  for (int i = 0; i < str.length(); i++) {
    if (i != str.length()) {
      result = result + str[i] + ' ';
    } else {
      result = result + str[i];
    }
  }
  return result;
}

int main() {
  bool keepGoing = true;
  while (keepGoing) {
    std::string input;
    std::cout << "Input a string or type \"QUIT\" to quit." << std::endl;
    getline(std::cin, input);
    if (input == "QUIT") {
      keepGoing = false;
    } else {
      std::cout << spaceString(input) << std::endl;
    }
  }
  return 0;
}
