// Buffer.h

#ifndef _Buffer_h_
#define _Buffer_h_

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

struct Player {
  std::string last;
  std::string first;
  std::string keyword;
  int year;
  std::string status;
  std::string category;
  inline bool operator<(const Player & p) const {
    return (last < p.last);
  }
  inline void operator<<(std::ostream & out) const {
    out << std::setw(6) << " Player Name:   " << last << ", " << first << std::endl;
    out << std::setw(6) << " Player Year:   " << year << " (" << category << ')' << std::endl;
    out << std::setw(6) << " Player Status: " << status << std::endl;
    out << std::endl;
  }
};

class Buffer {
public:
    void defaultDisplay() const;
    void statsDisplay() const;
    void listPlayers() const;
    void previousPlayer();
    void nextPlayer();
    bool insertPlayer(Player);
    void displaySearchResults();
    void saveAllToFile();
    void clearPlayers();
    Player getCurrentPlayer();
    bool editPlayer(Player);
    bool searchPlayers(std::string);
    bool openDatabase();
    int displayMode = 0;
    int currentYear = -1;

private:
    int displayedPlayer = 0;
    std::string yearToCategory(int yr);
    std::vector<Player> players;
    std::vector<int> searchResults;
    bool databaseOpen = false;
};

#endif
