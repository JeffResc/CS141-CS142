#include<iostream>
#include<fstream>
#include<ctime>
#include<string>
#include<stdlib.h>
#include<cstdlib>

int generateRandomLine();
int oppositeInt(int phase);
std::string readFileOfType(int categoryNumber, int randNum, int lineType);
void generateAsciiMan(int phase);
int mainDisplay(int phase);

// Stuct for storing the information about the current word
struct myWord {
  std::string word;
  std::string hintOne;
  std::string hintTwo;
};

// Declare variables used during the game
int categoryNumber;
bool guessWasGood;
bool continueGameplay = true;
bool multipleTimes = false;
int lineCount;
int randNum;
int lastRandNum = 0;
int phase;
std::string userInput;
std::string currentLine;

myWord word;
std::string pastGuesses;

int main() {
  // clear the screen to prepare for the game to start
  system("clear");
  // Loop the main menu until the user asks us to stop
  while(continueGameplay) {
    // Make sure at least one game has been played before showing this menu
    if (multipleTimes) {
      std::cout << "Continue playing? (yes/no): ";
      std::cin >> userInput;
      if (userInput != "yes") {
        std::cout << std::endl << "Exiting..." << std::endl;
        continueGameplay = false;
        return 0;
      } else {
        system("clear");
      }
    }
    // Show the main menu
    std::cout << "Welcome to ASCII man. Please choose between one of the following categories by choosing the category number:" << std::endl;
    std::cout << "Exit Game (0), US States (1), Desserts (2), Colors (3), Car Brands (4), Computer Brands (5)" << std::endl << std::endl << "Enter a category number: ";
    std::cin >> categoryNumber;
    if (categoryNumber == 0) {
      std::cout << "Exiting..." << std::endl;
      continueGameplay = false;
    // Generate the word and hint
    } else if (categoryNumber > 0 && categoryNumber <= 5) {
      randNum = generateRandomLine();
      word.word = readFileOfType(categoryNumber, randNum, 0);
      word.hintOne = readFileOfType(categoryNumber, randNum, 1);
      word.hintTwo = readFileOfType(categoryNumber, randNum, 2);
      pastGuesses = "";
      bool continueMainDisplay = true;
      phase = 6;
      bool winner = false;
      while (continueMainDisplay) {
        phase = mainDisplay(phase);
        if(phase == -5) {
          winner = true;
          continueMainDisplay = false;
        } else if (phase == 0) {
          continueMainDisplay = false;
        }
      }
      system("clear");
      if(winner) {
        generateAsciiMan(-1);
        std::cout << "Congratulations, you won!" << std::endl;
      } else {
        generateAsciiMan(0);
        std::cout << "Game over!" << std::endl;
        std::cout << "The word was: " << word.word << std::endl;
      }
    } else {
      system("clear");
      std::cout << "Category number invalid, please try again." << std::endl;
    }
    multipleTimes = true;
  }
  return 0;
}

// Function: generateRandomLine
// Description: Generates and returns a random number, 0-30
// Input: void
// Output: int (randNum)
int generateRandomLine() {
  // Set the randomizer
  srand(time(NULL));
  // Return a random number (0-30)
  randNum = std::rand() % 30;
  // Make sure the same number ins't drawn twice
  if (randNum == lastRandNum) {
    randNum = std::rand() % 30;
  }
  return randNum;
}

// Function: oppositeInt
// Description: Gets the inverse integer for integers 1-6
// Input: int (phase)
// Output: int (phase)
int oppositeInt(int phase) {
  if (phase == 0) {
    return 6;
  } else if (phase == 1) {
    return 5;
  } else if (phase == 2) {
    return 4;
  } else if (phase == 3) {
    return 3;
  } else if (phase == 4) {
    return 2;
  } else if (phase == 5) {
    return 1;
  } else if (phase == 6) {
    return 0;
  } else {
    return 6;
  }
}

// Function: readFileOfType
// Description: Reads the category files, with a given random number and line type
// Input: int (categoryNumber), int (randNum), int (lineType)
// Output: std::string (Various variables (Word, Hint1, Hint2))
std::string readFileOfType(int categoryNumber, int randNum, int lineType) {
  std::string categoryFilename;
  if (lineType == 1) {
    randNum = randNum + 30;
  } else if (lineType == 2) {
    randNum = randNum + 60;
  }
  // Open the correct file per the categoryNumber
  std::ifstream categoryFile;
  if (categoryNumber == 1) {
    categoryFilename = "asciimanData/states.list";
  } else if (categoryNumber == 2) {
    categoryFilename = "asciimanData/desserts.list";
  } else if (categoryNumber == 3) {
    categoryFilename = "asciimanData/colors.list";
  } else if (categoryNumber == 4) {
    categoryFilename = "asciimanData/carBrands.list";
  } else if (categoryNumber == 5) {
    categoryFilename = "asciimanData/computerBrands.list";
  }
  categoryFile.open(categoryFilename.c_str());
  categoryFile >> currentLine;
  lineCount = 0;
  while (std::getline(categoryFile, currentLine)) {
    if (lineCount == randNum) {
      return currentLine;
    }
    lineCount++;
  }
  // Close the file
  categoryFile.close();
  return "Error";
}

// Function: generateAsciiMan
// Description: Generates and displays the ASCII man at different phases
// Input: int (phase)
// Output: void
void generateAsciiMan(int phase) {
  if (phase == 6) {
    std::cout << "___________" << std::endl;
    std::cout << "|         |" << std::endl;
    std::cout << "|" << std::endl;
    std::cout << "|" << std::endl;
    std::cout << "|" << std::endl;
    std::cout << "|" << std::endl;
    std::cout << "|" << std::endl;
  } else if (phase == 5) {
    std::cout << "___________" << std::endl;
    std::cout << "|         |" << std::endl;
    std::cout << "|         0" << std::endl;
    std::cout << "|" << std::endl;
    std::cout << "|" << std::endl;
    std::cout << "|" << std::endl;
    std::cout << "|" << std::endl;
  } else if (phase == 4) {
    std::cout << "___________" << std::endl;
    std::cout << "|         |" << std::endl;
    std::cout << "|         0" << std::endl;
    std::cout << "|         |" << std::endl;
    std::cout << "|" << std::endl;
    std::cout << "|" << std::endl;
    std::cout << "|" << std::endl;
  } else if (phase == 3) {
    std::cout << "___________" << std::endl;
    std::cout << "|         |" << std::endl;
    std::cout << "|         0" << std::endl;
    std::cout << "|        /|" << std::endl;
    std::cout << "|" << std::endl;
    std::cout << "|" << std::endl;
    std::cout << "|" << std::endl;
  } else if (phase == 2) {
    std::cout << "___________" << std::endl;
    std::cout << "|         |" << std::endl;
    std::cout << "|         0" << std::endl;
    std::cout << "|        /|\\" << std::endl;
    std::cout << "|" << std::endl;
    std::cout << "|" << std::endl;
    std::cout << "|" << std::endl;
  } else if (phase == 1) {
    std::cout << "___________" << std::endl;
    std::cout << "|         |" << std::endl;
    std::cout << "|         0" << std::endl;
    std::cout << "|        /|\\" << std::endl;
    std::cout << "|        /" << std::endl;
    std::cout << "|" << std::endl;
    std::cout << "|" << std::endl;
  } else if (phase == 0) {
    std::cout << "___________" << std::endl;
    std::cout << "|         |" << std::endl;
    std::cout << "|         0" << std::endl;
    std::cout << "|        /|\\" << std::endl;
    std::cout << "|        / \\" << std::endl;
    std::cout << "|" << std::endl;
    std::cout << "|" << std::endl;
  } else if (phase == -1) {
    std::cout << "          7_O_/" << std::endl;
    std::cout << "           (/" << std::endl;
    std::cout << "           /\\/'" << std::endl;
    std::cout << "           7" << std::endl;
  }
  std::cout << std::endl;
}

int mainDisplay(int phase) {
  system("clear");
  generateAsciiMan(phase);
  char letter;
  std::string currString;
  for(int x=0;x<word.word.length();x++) {
    currString += '-';
  }
  for(int j=0;j<pastGuesses.length();j++) {
    for(int i = 0; i < word.word.length(); i++) {
      if (word.word[i] == pastGuesses[j]) {
        currString[i] = pastGuesses[j];
      }
    }
  }
  std::cout << currString << std::endl;
  if (phase < 6) {
    std::cout << "Wrong Guesses Left: " << phase-1 << std::endl;
  } else {
    std::cout << std::endl;
  }
  if (phase < 3) {
    std::cout << "Hint 1: " << word.hintOne << std::endl;
  } else {
    std::cout << std::endl;
  }
  if (phase < 2) {
    std::cout << "Hint 2: " << word.hintTwo << std::endl;
  } else {
    std::cout << std::endl;
  }
  if (currString == word.word) {
    return -5;
  }
  std::cout << "Enter a guess: ";
  std::cin >> letter;
  bool setInPastGuesses = true;
  for(int j=0;j<pastGuesses.length();j++) {
    if(pastGuesses[j] == toupper(letter)) {
      setInPastGuesses = false;
    }
  }
  if(setInPastGuesses) {
    pastGuesses += toupper(letter);
  }
  guessWasGood = false;
  for(int i = 0; i < word.word.length(); i++) {
    if (word.word[i] == toupper(letter)) {
      guessWasGood = true;
    }
  }
  if (!guessWasGood) {
    phase = phase - 1;
  }
  std::cout << std::endl;
  return phase;
}
