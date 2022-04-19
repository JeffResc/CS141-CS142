#include<iostream>
#include<string>
#include<fstream>

struct Movie {
  std::string movieName;
  int year;
  float gross;
};

int showMainMenu();
void ShowAll();
void ShowByYear();

Movie AllMovies[50];

int main() {
  // Read all movies from the file and put each into the AllMovies array
  std::ifstream inputFileStream;
  inputFileStream.open("moviedata.txt");
  int movieNumber = 0;
  while(!inputFileStream.eof()) {
    inputFileStream >> AllMovies[movieNumber].movieName >> AllMovies[movieNumber].year >> AllMovies[movieNumber].gross;
    movieNumber++;
  }
  inputFileStream.close();
  // Done reading the file, show the main menu and return which option the user selected
  bool continueLoop = true;
  while(continueLoop) {
    int menuOption = showMainMenu();
    if (menuOption == 1) {
      ShowAll();
    } else if (menuOption == 2) {
      ShowByYear();
    } else if (menuOption == 3) {
      continueLoop = false;
    } else {
      std::cout << "Input not recognized, please input an integer 1-3." << std::endl;
    }
  }
  std::cout << "Goodbye!" << std::endl;
  return 0;
}

int showMainMenu() {
  int menuOption;
  std::cout << "-----------------------------";
  std::cout << std::endl;
  std::cout << "Welcome to the movie program.";
  std::cout << std::endl << std::endl;
  std::cout << "Select from one of the following menu options:";
  std::cout << std::endl;
  std::cout << "[1] Show all movies";
  std::cout << std::endl;
  std::cout << "[2] Show movie statistics by year";
  std::cout << std::endl;
  std::cout << "[3] Quit the program";
  std::cout << std::endl;
  std::cin >> menuOption;
  return menuOption;
}

void ShowAll() {
  for(int i=0; i < 50; i++) {
    std::cout << AllMovies[i].movieName << " " << AllMovies[i].year << " " << AllMovies[i].gross << std::endl;
  }
}

void ShowByYear() {
  int year;
  float highestGross;
  int highestGrossNum;
  float lowestGross;
  int lowestGrossNum;
  float grossSum = 0;
  float avgGross;
  int hitNumber = 0;
  std::cout << "Please input a year: ";
  std::cin >> year;
  for(int i=0; i < 50; i++) {
    if (AllMovies[i].year == year) {
      if (hitNumber == 0) {
        highestGross = AllMovies[i].gross;
        highestGrossNum = i;
        lowestGross = AllMovies[i].gross;
        lowestGrossNum = i;
        grossSum = AllMovies[i].gross;
      } else {
        if (AllMovies[i].gross > highestGross) {
          highestGross = AllMovies[i].gross;
          highestGrossNum = i;
        }
        if (AllMovies[i].gross < lowestGross) {
          lowestGross = AllMovies[i].gross;
          lowestGrossNum = i;
        }
        grossSum = grossSum + AllMovies[i].gross;
      }
      hitNumber++;
    }
  }
  if(hitNumber > 0) {
    avgGross = grossSum / hitNumber;
    std::cout << "Total number of movies: " << hitNumber << std::endl;
    std::cout << "Highest grossing: " << AllMovies[highestGrossNum].movieName << " " << AllMovies[highestGrossNum].year << " " << AllMovies[highestGrossNum].gross << std::endl;
    std::cout << "Lowest grossing: " << AllMovies[lowestGrossNum].movieName << " " << AllMovies[lowestGrossNum].year << " " << AllMovies[lowestGrossNum].gross << std::endl;
    std::cout << "Average: " << avgGross << std::endl;
  } else {
    std::cout << "No movies were found in the year " << year << "." << std::endl;
  }
}
