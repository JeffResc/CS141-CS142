#include<iostream>
#include<string>

int main() {
  bool looping = true;
  bool firstCharUpper;
  bool allElseLower;
  bool areDigits;
  std::string userInput;

  while(looping) {
    firstCharUpper = true;
    allElseLower = true;
    std::cout << "Input a first name: ";
    std::cin >> userInput;
    if (userInput.length() >= 2 && userInput.length() <= 10) {
      if (!isupper(userInput[0])) {
        firstCharUpper = false;
      }
      for(std::string::size_type i = 0; i < userInput.size(); ++i) {
        if (i != 0) {
          if (!islower(userInput[i])) {
            allElseLower = false;
          }
        }
      }
    } else {
      firstCharUpper = false;
    }
    if (firstCharUpper && allElseLower) {
      looping = false;
    } else {
      std::cout << "Results Invalid!" << std::endl;
    }
  }

  looping = true;
  std::cout << "Results Ok!" << std::endl;

  while(looping) {
    firstCharUpper = true;
    allElseLower = true;
    std::cout << "Input a last name: ";
    std::cin >> userInput;
    if (userInput.length() >= 2 && userInput.length() <= 10) {
      if (!isupper(userInput[0])) {
        firstCharUpper = false;
      }
      for(std::string::size_type i = 0; i < userInput.size(); ++i) {
        if (i != 0) {
          if (!islower(userInput[i])) {
            allElseLower = false;
          }
        }
      }
    } else {
      firstCharUpper = false;
    }
    if (firstCharUpper && allElseLower) {
      looping = false;
    } else {
      std::cout << "Results Invalid!" << std::endl;
    }
  }

  looping = true;
  std::cout << "Results Ok!" << std::endl;

  while(looping) {
    std::cout << "Input a state code: ";
    std::cin >> userInput;
    if (userInput.length() == 2 && isupper(userInput[0]) && isupper(userInput[1])) {
      looping = false;
    } else {
      std::cout << "Results Invalid!" << std::endl;
    }
  }

  looping = true;
  std::cout << "Results Ok!" << std::endl;

  while(looping) {
    areDigits = true;
    std::cout << "Input a zip code: ";
    std::cin >> userInput;
    if (userInput.length() == 5) {
      for(std::string::size_type i = 0; i < userInput.size(); ++i) {
        if (!isdigit(userInput[i])) {
          areDigits = false;
        }
      }
    } else {
      areDigits = false;
    }
    if (areDigits) {
      looping = false;
    } else {
      std::cout << "Results Invalid!" << std::endl;
    }
  }

  std::cout << "Results Ok!" << std::endl;
  return 0;
}
