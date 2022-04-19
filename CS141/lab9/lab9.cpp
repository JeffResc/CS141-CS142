#include<iostream>
#include<string>
#include<fstream>

std::string readData();
int computeShift(std::string);
std::string decodeData(std::string, int);
void writeData(std::string);

int main() {
  std::string encodedText;
  std::string decodedData;
  int shift;

  encodedText = readData();
  shift = computeShift(encodedText);
  decodedData = decodeData(encodedText, shift);
  writeData(decodedData);
  return 0;
}

std::string readData() {
  std::ifstream inputFileStream;
  std::string encodedText;
  std::string userInput;
  char ch;

  // Ask user for the input file
  std::cout << "Enter a filename to read from: ";
  std::cin >> userInput;
  if (userInput != "encoded.txt") {
    std::cout << "Incorrect filename." << std::endl;
    return 0;
  }
  inputFileStream.open(userInput.c_str());
  while(inputFileStream.get(ch)) {
    encodedText += ch;
  }
  inputFileStream.close();
  return encodedText;
}

int computeShift(std::string encodedText) {
  int shift;
  int charNum;
  int currLargestChar;
  int currLargestValue = 0;
  int charCount [26];

  for(int i = 0; i <= 26; i++) {
    charCount[i] = 0;
  }
  for(int i=0; i < encodedText.length(); i++) {
    charNum = int(tolower(encodedText[i])) - 97;
    if (isalpha(tolower(encodedText[i]))) {
      if (charNum <= 26) {
        charCount[charNum]++;
      }
    }
  }
 for(int i = 0; i <= 26; i++) {
   if (currLargestValue < charCount[i]) {
     currLargestChar = i;
     currLargestValue = charCount[i];
   }
 }
 shift = currLargestChar - (int('e')-97);
 return shift;
}

std::string decodeData(std::string encodedText, int shift) {
  char ch;
  int charNum;
  std::string decodedData;

  for(int i=0; i < encodedText.length(); i++) {
    if (isalpha(encodedText[i])) {
      charNum = int(tolower(encodedText[i])) - shift;
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

void writeData(std::string decodedData) {
  std::ofstream outputFileStream;
  std::string userInput;
  std::cout << "Enter a filename to write to: ";
  std::cin >> userInput;
  outputFileStream.open(userInput.c_str());
  outputFileStream << decodedData;
  outputFileStream.close();
}
