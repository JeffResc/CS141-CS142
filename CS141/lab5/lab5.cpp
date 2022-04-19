#include<iostream>
#include<string>

int main() {
  // Setup the basic variables
  std::string userInput;
  const std::string originalString = "the quick brown fox jumped right over the lazy dog.";
  std::string myStr = originalString;

  // Ask the user for their input
  std::cout << "Input a character or string to search for: ";
  std::cin >> userInput;
  std::cout << std::endl;

  // Declare a few variables that will help us during the while loop
  bool continueLoop = true;
  bool foundAtLastOne = false;
  std::string placesFound;

  // Start a while loop to find all occurances of the character or string within the original string
  while(continueLoop) {
    // Search for the userInput within the original string
    std::size_t search = myStr.find(userInput);
    // If string is found in the original string and is not empty, trunculate myStr to remove any characters leading up to where userInput was found
    if (search!=std::string::npos) {
      // Output the location that the input was found at
      std::cout << "Your input was found at the following location: {" << (originalString.length()-myStr.length()) + search << "," << (originalString.length()-myStr.length()) +search + userInput.length() << "}" << std::endl;
      // Trunculate myStr so that the while loop doesn't search the same location during the next iteration
      myStr = myStr.substr (search+userInput.length(),myStr.length());
      foundAtLastOne = true;
    // If string is not found in the original string, stop the while loop
    } else {
      continueLoop = false;
    }
  }

  // If we didn't find the input, let the user know
  if (!foundAtLastOne) {
    std::cout << "Could not find your input within the original string." << std::endl;
  }
}
