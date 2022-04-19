#include<iostream>
#include<string>
#include<fstream>

// Define the variables used throughout the program
bool continueLooping;
bool zipCodeMatched;
bool forLoopMatch;
std::string userInput;
std::string zipCode;

// Define the user-defined functions
bool isValidName(std::string);
bool isValidStateCode(std::string);
bool isValidZipCode(std::string);
bool isValidPhoneNumber(std::string);

int main() {
  // Initialize the loop
  continueLooping = true;

  // Verify the first name
  while(continueLooping) {
    std::cout << "Enter a first name: ";
    std::cin >> userInput;
    // Check if userInput is a valid name
    if(isValidName(userInput)) {
      // Return the results if true
      std::cout << "Results Ok!";
      continueLooping = false;
    }
  }

  // Reset the loop
  continueLooping = true;
  std::cout << std::endl;

  // Verify the middle name
  while(continueLooping) {
    std::cout << "Enter a middle name: ";
    std::cin >> userInput;
    // Check to see if the user wants to skip this step
    if (userInput == "none") {
      std::cout << "Skipping...";
      continueLooping = false;
    // Otherwise, check to see if userInput is a valid name
    } else if(isValidName(userInput)) {
      // Return the results if true
      std::cout << "Results Ok!";
      continueLooping = false;
    }
  }

  // Reset the loop
  continueLooping = true;
  std::cout << std::endl;

  // Verify the last name
  while(continueLooping) {
    std::cout << "Enter a last name: ";
    std::cin >> userInput;
    // Check to see if userInput is a valid name
    if(isValidName(userInput)) {
      // Return the results if true
      std::cout << "Results Ok!";
      continueLooping = false;
    }
  }

  // Reset the loop
  continueLooping = true;
  std::cout << std::endl;

  // Verify the state code
  while(continueLooping) {
    std::cout << "Enter a state code: ";
    std::cin >> userInput;
    // Check to see if userInput is a valid state code
    if(isValidStateCode(userInput)) {
      // Return the results if true
      std::cout << "Results Ok!";
      continueLooping = false;
    }
  }

  // Reset the loop
  continueLooping = true;
  std::cout << std::endl;

  // Verify the zip code
  while(continueLooping) {
    std::cout << "Enter a zip code: ";
    std::cin >> userInput;
    // Check to see if userInput is a valid zip code
    if(isValidZipCode(userInput)) {
      // Return the results if true
      std::cout << "Results Ok!";
      continueLooping = false;
    }
  }

  // Reset the loop
  continueLooping = true;
  std::cout << std::endl;

  // Verify the phone number
  while(continueLooping) {
    std::cout << "Enter a phone number: ";
    std::cin >> userInput;
    // Check to see if userInput is a valid phone number
    if(isValidPhoneNumber(userInput)) {
      // Return the results if true
      std::cout << "Results Ok!";
      continueLooping = false;
    }
  }
}

// Function: isValidName
// Input: std::string (inputName)
// Output: bool (If Name is Valid or Not)
bool isValidName(std::string inputName) {
  // Check if inputName is between 2 and 10 characters in length
  if (inputName.length() >= 2 && inputName.length() <= 10) {
    forLoopMatch = true;
    // Run for loop for each character
    for (int i = 0; i < inputName.length(); i++) {
      // Check if the character should be uppercase (first character or character after hyphen) and if it isn't uppercase, set forLoopMatch to false
      if ((i == 0 || inputName[i-1] == '-') && !isupper(inputName[i])) {
        forLoopMatch = false;
      // Check if the character should be lowercase (not the first character or character after hyphen) and if it isn't lowercase, set forLoopMatch to false
      } else if ((!isalpha(inputName[i]) || (!islower(inputName[i]))) && inputName[i] != '-' && !(i == 0 || inputName[i-1] == '-')) {
        forLoopMatch = false;
      }
    }
    // Check if forLoopMatch was ever set to false during the for loop and if it was, be sure to return that value, if not, return true
    if (forLoopMatch) {
      return true;
    } else {
      return false;
    }
  } else {
    // Return false if inputName isn't between 2 and 10 characters in length
    return false;
  }
}

// Function: isValidStateCode
// Input: std::string (inputStateCode)
// Output: bool (If State Code is Valid or Not)
bool isValidStateCode(std::string inputStateCode) {
  // Check if inputStateCode is 2 characters in length and both characters are uppercase
  if (inputStateCode.length() == 2 && isupper(inputStateCode[0]) && isupper(inputStateCode[1])) {
    return true;
  } else {
    return false;
  }
}

// Function: isValidZipCode
// Input: std::string (inputZipCode)
// Output: bool (If Zip Code is Valid or Not)
bool isValidZipCode(std::string inputZipCode) {
  // Read the file "zipcodes.txt"
  std::ifstream zipCodesTXT;
  zipCodesTXT.open("zipcodes.txt");
  zipCodesTXT >> zipCode;
  zipCodeMatched = false;
  // Check if the inputZipCode is 5 characters in length and the last two characters are digits
  if (inputZipCode.length() == 5 && isdigit(inputZipCode[3]) && isdigit(inputZipCode[4])) {
    // Read through the entire file, "zipcodes.txt"
    while(!zipCodesTXT.eof()) {
      // Matches first three digits of inputZipCode to zipCode (from zipcodes.txt)
      if (zipCode[0] == inputZipCode[0] && zipCode[1] == inputZipCode[1] && zipCode[2] == inputZipCode[2]) {
        // If we matched the first three characters, set zipCodeMatched to true
        zipCodeMatched = true;
      }
      zipCodesTXT >> zipCode;
    }
    // If the zip code was matched, return the results
    return zipCodeMatched;
  // If the zip code wasn't 5 characters in length or the last two characters weren't digits, return false
  } else {
    return false;
  }
  zipCodesTXT.close();
  // Return false if we never returned true to prevent a false-positive
  return false;
}

// Function: isValidPhoneNumber
// Input: std::string (inputPhoneNumber)
// Output: bool (If Phone Number is Valid or Not)
bool isValidPhoneNumber(std::string inputPhoneNumber) {
  forLoopMatch = true;
  // If the inputPhoneNumber is 14 characters in length
  if (inputPhoneNumber.length() == 14) {
    // Check formatting to ensure the '(' is in position 0, the ')' is in position 4 and the '-' is in either position 5 or position 9
    // If any other position, ensure that the character is a digit, otherwise set forLoopMatch to false
    for(int i = 0; i < 14; i++) {
      if (i == 0) {
        if (inputPhoneNumber[i] != '(') {
          forLoopMatch = false;
          std::cout << i << std::endl;
        }
      } else if (i == 4) {
        if (inputPhoneNumber[i] != ')') {
          forLoopMatch = false;
          std::cout << i << std::endl;
        }
      } else if (i == 5 || i == 9) {
        if (inputPhoneNumber[i] != '-') {
          forLoopMatch = false;
          std::cout << i << std::endl;
        }
      } else {
        if (!isdigit(inputPhoneNumber[i])) {
          forLoopMatch = false;
          std::cout << i << std::endl;
        }
      }
    }
    // If the inputPhoneNumber is 12 characters in length
  } else if (inputPhoneNumber.length() == 12) {
    // Check formatting to ensure the '-' is in either position 3 or position 7
    // If any other position, ensure that the character is a digit, otherwise set forLoopMatch to false
    for(int i = 0; i < 12; i++) {
      if (i == 3 || i == 7) {
        if (inputPhoneNumber[i] != '-') {
          forLoopMatch = false;
        }
      } else {
        if (!isdigit(inputPhoneNumber[i])) {
          forLoopMatch = false;
        }
      }
    }
  // If the inputPhoneNumber is 14 or 12 characters, return false
  } else {
    return false;
  }
  // Check that the forLoopMatch was set by verifying the inputPhoneNumber was either 12 or 14 characters
  // And return the forLoopMatch
  if (inputPhoneNumber.length() == 14 || inputPhoneNumber.length() == 12) {
    return forLoopMatch;
  } else {
    return false;
  }
}
