/*
  Jeffrey Rescignano <rescigjj@clarkson.edu>
  CS142 - Project 2, SoccerManager.cpp
  https://people.clarkson.edu/~alexis/CS142/Assignments/project2.pdf
*/

#include "SoccerManager.h"

void SoccerManager::display() {
    const std::string long_separator(115, '-');

    system(clear_command);

    if (!buffer_.openDatabase()) {
      message_ = "Unable to open database file. It either does not exist or is misformatted.";
    }

    std::cout << "Soccer Manager" << std::endl;
    std::cout << long_separator << std::endl;
    switch (buffer_.displayMode) {
      case 3:
        buffer_.displaySearchResults();
        break;
      case 7:
        buffer_.listPlayers();
        break;
      case 8:
        buffer_.statsDisplay();
        break;
      default:
        buffer_.defaultDisplay();
        break;
    }
    std::cout << long_separator << std::endl;
    switch (buffer_.displayMode) {
      case 7:
        std::cout << "(9)[Save & Quit] (0)[Back Main View]" << std::endl;
        break;
      case 8:
        std::cout << "(9)[Save & Quit] (0)[Back Main View]" << std::endl;
        break;
      default:
        std::cout << "(1)[Start season] (2)[Add player] (3)[Search] (4)[Prev] (5)[Next] (6)[Edit] (7)[List] (8)[Stats] (9)[Save & Quit]" << std::endl;
        break;
    }
    std::cout << long_separator << std::endl;
    if (!message_.empty()) {
        std::cout << message_ << std::endl;
        message_.clear();
    }
}

void SoccerManager::execute_command(char command, bool & done)
{
    switch (command) {
        // Start a new season
        case '1': {
            std::cout << "Are you sure? (y/n): ";
            char c = getchar();
            if (c == 'y') {
              std::string yr;
              std::cout << "Enter new season year: ";
              std::cin >> yr;
              bool isInt = true;
              for(int i = 0; i < yr.length(); i++) {
                if (!std::isdigit(yr[i])) {
                  isInt = false;
                } else {
                }
              }
              if(isInt) {
                buffer_.displayMode = 0;
                buffer_.clearPlayers();
                buffer_.currentYear = atoi(yr.c_str());
                message_ = "Successfully started new season";
              } else {
                message_ = "ERROR: Unable to create new season, year invalid";
              }
            }
            break;
        }

        // Add a player
        case '2': {
            Player newPlayer;
            std::cout << "Last name: ";
            getline(std::cin, newPlayer.last);
            std::cout << "First name: ";
            getline(std::cin, newPlayer.first);
            std::cout << "Keyword: ";
            getline(std::cin, newPlayer.keyword);
            std::cout << "Status: ";
            getline(std::cin, newPlayer.status);
            std::cout << "Birth year: ";
            std::cin >> newPlayer.year;
            bool success = buffer_.insertPlayer(newPlayer);
            if (!success) {
              message_ = "ERROR: Unable to add player due to reason: Invalid birth year for this league";
            } else {
              message_ = "Successfully added player";
            }
            break;
        }

        // Search players
        case '3': {
            std::cout << "Search query: ";
            std::string searchQuery;
            getline(std::cin, searchQuery);
            bool success = buffer_.searchPlayers(searchQuery);
            if (!success) {
              message_ = "ERROR: Could not find any players matching those search parameters.";
            } else {
              buffer_.displayMode = 3;
            }
            break;
        }

        // Previous Player
        case '4': {
            buffer_.displayMode = 0;
            buffer_.previousPlayer();
            break;
        }

        // Next player
        case '5': {
            buffer_.displayMode = 0;
            buffer_.nextPlayer();
            break;
        }

        // Edit player
        case '6': {
            if(buffer_.displayMode == 0) {
              Player p = buffer_.getCurrentPlayer();
              std::string newLast;
              std::string newFirst;
              std::string newKeyword;
              std::string newStatus;
              std::string newYear;

              std::cout << "Last name [" <<  p.last << "]: ";
              getline(std::cin, newLast);
              std::cout << "First name [" << p.first << "]: ";
              getline(std::cin, newFirst);
              std::cout << "Keyword [" << p.keyword <<"]: ";
              getline(std::cin, newKeyword);
              std::cout << "Status [" << p.status << "]:";
              getline(std::cin, newStatus);
              std::cout << "Birth year [" << p.year << "]: ";
              getline(std::cin, newYear);

              if(!newLast.empty()) {
                p.last = newLast;
              }
              if(!newFirst.empty()) {
                p.first = newFirst;
              }
              if(!newKeyword.empty()) {
                p.keyword = newKeyword;
              }
              if(!newStatus.empty()) {
                p.status = newStatus;
              }
              if(!newYear.empty()) {
                p.year = atoi(newYear.c_str());
              }
              bool success = buffer_.editPlayer(p);
              if (success) {
                message_ = "Successfully edited player.";
              } else {
                message_ = "ERROR: Unable to add player due to reason: Invalid birth year for this league";
              }
            } else {
              message_ = "ERROR: Unable to edit player, please enter a display mode where only one player is shown.";
            }
            break;
        }

        // List players
        case '7': {
            buffer_.displayMode = 7;
            break;
        }

        // Statistics
        case '8': {
            buffer_.displayMode = 8;
            break;
        }

        // Quit
        case '9': {
            buffer_.saveAllToFile();
            done = true;
            break;
        }

        // Main View
        case '0': {
          buffer_.displayMode = 0;
          break;
        }

        default: {
          message_ = "ERROR: Invalid command, try again.";
          break;
        }
    }
}

void SoccerManager::run() {
    bool done = false;
    while (!done) {
        display();

        std::cout << "Command #: ";
        char command;
        std::cin >> command;
        std::cin.get(); // '\n'

        execute_command(command, done);

        std::cout << std::endl;
    }
}
