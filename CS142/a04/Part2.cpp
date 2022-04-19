#include <fstream>
#include <iostream>

class Song {
public:
  // Define the constructor and default constructors
  Song() : Title("invalid"), Artist("invalid"), Year(-1) {}
  Song(const std::string & title) : Title(title), Artist("unknown"), Year(-1) {}
  Song(const std::string & title, const std::string & artist, const int & year) : Title(title), Artist(artist), Year(year) {}

  /* Method: operator<<(std::ostream & out).
    Description: Prints all variables in class Song to specified std::ostream. */
  inline void operator<<(std::ostream & out) const {
    out << Title << std::endl;
    out << Artist << std::endl;
    out << Year << std::endl;
  }
  /* Method: operator>>(std::istream & in).
     Description: Reads data from std::istrem to populate all variables in class Song. */
  void operator>>(std::istream & in) {
    std::getline(in, Title);
    std::getline(in, Artist);
    in >> Year;
    in.get();
  }
  /* Method: operator==(const Song & other)
     Description: Returns true if the receiver and the argument have the same title, artist and recording year */
  inline bool operator==(const Song & other) const {
    if (other.Title == Title && other.Artist == Artist && other.Year == Year)
      return true;
    return false;
  }
  /* Method: operator<(const Song & other)
     Description: returns true if the title of the first song is less than the title of the second song. In case the titles of the two songs are identical, the operator returns true if the artist of the first song is less than the artist of the second song. In case the titles and artists of the two songs are identical, the operator returns true if the first song was recorded before the second one. In all other cases, the operator returns false. */
  bool operator<(const Song & other) const {
    if ((Title < other.Title) || (Title == other.Title && Artist < other.Artist) || (Title == other.Title && Artist == other.Artist && Year < other.Year)) {
      return true;
    } else {
      return false;
    }
  }

  /* Method: title()
     Description: Returns the song title by constant reference. */
  inline const std::string & title() const {
    return Title;
  }
  /* Method: artist()
     Description: Returns the song artist by constant reference. */
  inline const std::string & artist() const {
    return Artist;
  }
  /* Method: year()
     Description: Returns the song year by constant reference. */
  inline const int & year() const {
    return Year;
  }

  /* Method: set_title(const std::string & titles)
     Description: Sets the song title to the given string. */
  inline void set_title(const std::string & title) {
    Title = title;
  }
  /* Method: set_artist(const std::string & artist)
     Description: Sets the artist title to the given string. */
  inline void set_artist(const std::string & artist) {
    Artist = artist;
  }
  /* Method: set_year(const int & year)
     Description: Sets the year title to the given integer. */
  inline void set_year(const int & year) {
    Year = year;
  }
  /* Method: set(const std::string & title, const std::string & artist, const int & year)
     Description: Sets the title, artist and year of the song to the given values */
  inline void set(const std::string & title, const std::string & artist, const int & year) {
    Title = title;
    Artist = artist;
    Year = year;
  }
private:
  std::string Title, Artist;
  int Year;
};

Song readSong(std::ifstream & ifs) {
  std::string title;
  std::string artist;
  std::string year;
  Song song;
  getline(ifs, title);
  getline(ifs, artist);
  getline(ifs, year);
  if (!ifs.eof() || !ifs.fail()) {
    song.set(title, artist, std::stoi(year));
  } else {
    song.set("-1", "-1", -1);
  }
  return song;
}

int main() {
  std::ifstream ifs;
  std::string filename;
  std::cout << "Input a filename: ";
  std::cin >> filename;
  ifs.open(filename.c_str());
  bool keepGoing = true;
  while (keepGoing) {
    Song song = readSong(ifs);
    if(song.title() == "-1" && song.artist() == "-1" && song.year() == -1) {
      keepGoing = false;
    } else {
      song << std::cout;
    }
  }
}
