// Buffer.cpp

#include <sstream>
#include <algorithm>
#include <vector>
#include "Buffer.h"

void Buffer::defaultDisplay() const {
  if(players.size() > 0) {
     players[displayedPlayer] << std::cout;
  }
}

void Buffer::listPlayers() const {
  for(int i=0; i < players.size(); i++) {
    players[i] << std::cout;
  }
}

void Buffer::displaySearchResults() {
  if(searchResults.size() > 0) {
    for(int i=0; i < searchResults.size(); i++) {
        players[searchResults[i]] << std::cout;
    }
  }
}

bool Buffer::searchPlayers(std::string searchQuery) {
  std::vector<std::string> lastNames;
  std::vector<std::string> firstNames;
  std::vector<std::string> keywords;
  searchResults.clear();

  for(int i=0; i < players.size(); i++) {
    lastNames.push_back(players[i].last);
    firstNames.push_back(players[i].first);
    keywords.push_back(players[i].keyword);
  }

  std::vector<std::string>::iterator lastNamesSearch = std::find(lastNames.begin(), lastNames.end(), searchQuery);
  if (lastNamesSearch != lastNames.end()) {
      searchResults.push_back(lastNamesSearch - lastNames.begin());
  }

  std::vector<std::string>::iterator firstNamesSearch = std::find(firstNames.begin(), firstNames.end(), searchQuery);
  if (firstNamesSearch != firstNames.end()) {
      searchResults.push_back(firstNamesSearch - firstNames.begin());
  }

  std::vector<std::string>::iterator keywordsSearch = std::find(keywords.begin(), keywords.end(), searchQuery);
  if (keywordsSearch != keywords.end()) {
      searchResults.push_back(keywordsSearch - keywords.begin());
  }

  return (searchResults.size() > 0);
}

void Buffer::statsDisplay() const {
  int uSixCount = 0;
  int uEightCount = 0;
  int uTenCount = 0;
  int uTwelveCount = 0;
  int uFourteenCount = 0;
  int uSixteenCount = 0;
  int paidCount = 0;
  int unpaidCount = 0;
  for(int i=0; i < players.size(); i++) {
    if (players[i].category == "U6") {
      uSixCount++;
    } else if (players[i].category == "U8") {
      uEightCount++;
    } else if (players[i].category == "U10") {
      uTenCount++;
    } else if (players[i].category == "U12") {
      uTwelveCount++;
    } else if (players[i].category == "U14") {
      uFourteenCount++;
    } else if (players[i].category == "U16") {
      uSixteenCount++;
    }
    if (players[i].status == "Paid") {
      paidCount++;
    } else if (players[i].status == "Unpaid") {
      unpaidCount++;
    }
  }
  std::cout << std::setw(6) << " Total Players: " << players.size() << std::endl;
  std::cout << std::setw(6) << " Total Unpaid:  " << unpaidCount << std::endl;
  std::cout << std::setw(6) << " Total Paid:    " << paidCount << std::endl;
  std::cout << std::setw(6) << " U6 Count:      " << uSixCount << std::endl;
  std::cout << std::setw(6) << " U8 Count:      " << uEightCount << std::endl;
  std::cout << std::setw(6) << " U10 Count:     " << uTenCount << std::endl;
  std::cout << std::setw(6) << " U12 Count:     " << uTwelveCount << std::endl;
  std::cout << std::setw(6) << " U14 Count:     " << uFourteenCount << std::endl;
  std::cout << std::setw(6) << " U16 Count:     " << uSixteenCount << std::endl;
  std::cout << std::endl;
}

void Buffer::previousPlayer() {
  if (displayedPlayer-1 == -1)  {
    displayedPlayer = players.size()-1;
  } else {
    displayedPlayer--;
  }
  std::cout << displayedPlayer << std::endl;
}

void Buffer::nextPlayer() {
  if (displayedPlayer+1 == players.size()) {
    displayedPlayer = 0;
  } else {
    displayedPlayer++;
  }
}

std::string Buffer::yearToCategory(int yr) {
  int age = currentYear - yr;
  if(age < 6 && age > 4) {
    return "U6";
  } else if (age == 6 || age == 7) {
    return "U8";
  } else if (age == 8 || age == 9) {
    return "U10";
  } else if (age == 10 || age == 11) {
    return "U12";
  } else if (age == 12 || age == 13) {
    return "U14";
  } else if (age == 14 || age == 15) {
    return "U16";
  } else {
    return "Invalid";
  }
}

void Buffer::clearPlayers() {
  displayedPlayer = 0;
  players.clear();
}

bool Buffer::insertPlayer(Player p) {
  p.category = yearToCategory(p.year);
  if (p.category != "Invalid") {
    players.push_back(p);
    std::sort(players.begin(), players.end());
    return true;
  } else {
    return false;
  }
}

bool Buffer::editPlayer(Player p) {
  p.category = yearToCategory(p.year);
  if (p.category != "Invalid") {
    players[displayedPlayer] = p;
    std::sort(players.begin(), players.end());
    return true;
  } else {
    return false;
  }
}

Player Buffer::getCurrentPlayer() {
  return players[displayedPlayer];
}

void Buffer::saveAllToFile() {
  std::ofstream ofs;
  ofs.open("database.txt");
  ofs << "YEAR " << currentYear << '\n';
  for(int i=0; i < players.size(); i++) {
    ofs << players[i].last << ' ' << players[i].first << ' '  << players[i].keyword << ' ' << players[i].year << ' ' << players[i].status << '\n';
  }
  ofs.close();
}

bool Buffer::openDatabase() {
  if (!databaseOpen) {
    databaseOpen = true;
    std::ifstream ifs;
    ifs.open("database.txt");

    std::string yr;
    ifs >> yr;

    if (yr == "YEAR") {
      ifs >> currentYear;
      std::string last;
      while(ifs >> last) {
        Player newPlayer;
        newPlayer.last = last;
        ifs >> newPlayer.first;
        ifs >> newPlayer.keyword;
        ifs >> newPlayer.year;
        ifs >> newPlayer.status;
        newPlayer.category = yearToCategory(newPlayer.year);
        players.push_back(newPlayer);
      }
      ifs.close();
      std::sort(players.begin(), players.end());
      return true;
    } else {
      return false;
    }
  } else {
    return true;
  }
}
