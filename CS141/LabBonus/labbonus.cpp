#include<iostream>
#include<string>

std::string decodeData(std::string, int, std::string);

int main() {
  std::string theWord;
  std::string shiftDirection;
  int shiftNum;
  
  std::cout << "Welcome to the lab bonus program. Follow the prompts on the screen or type \"q!\" to quit." << std::endl;
  bool shouldContinue = true;
  while (shouldContinue) {
    std::cout << "--------------------" << std::endl;
    std::cout << "Enter a word: ";
    std::cin >> theWord;
    if (theWord != "q!") {
      std::cout << "Enter a shift direction (LEFT/RIGHT): ";
      std::cin >> shiftDirection;
      if (shiftDirection == "LEFT" || shiftDirection == "RIGHT") {
        std::cout << "Enter a shift amount (1-26): ";
        std::cin >> shiftNum;
        if (shiftNum > 0 && shiftNum < 27) {
          std::cout << theWord << " -----> " << decodeData(theWord, shiftNum, shiftDirection) << std::endl;
        } else {
          std::cout << "Shift amount must be greater than 0 and less than 27." << std::endl;
        }
      } else {
        std::cout << "Shift direction must be \"LEFT\" or \"RIGHT.\"" << std::endl;
      }
    } else {
      shouldContinue = false;
    }
  }
  std::cout << "Goodbye!" << std::endl;
  return 0;
}

std::string decodeData(std::string encodedText, int shift, std::string direction) {
  char ch;
  int charNum;
  std::string decodedData;

  for(int i=0; i < encodedText.length(); i++) {
    if (isalpha(encodedText[i])) {
      if (direction == "LEFT") {
        charNum = int(tolower(encodedText[i])) - shift;
      } else {
        charNum = int(tolower(encodedText[i])) + shift;
      }
      if (charNum < 97) {
        charNum = charNum + 26;
      }
      ch = charNum;
      decodedData += ch;
    } else {
      decodedData += encodedText[i];
    }
  }
  return decodedData;
}
