#include<iostream>
#include<fstream>
#include<istream>
#include<string>

class Song {
public:
  // Define the constructor and default constructors
  Song() : Title("invalid"), Artist("invalid"), Year(-1) {}
  Song(const std::string & title) : Title(title), Artist("unknown"), Year(-1) {}
  Song(const std::string & title, const std::string & artist, const int & year) : Title(title), Artist(artist), Year(year) {}
  // Method: print(std::ostream & out).
  // Description: Prints all variables in class Song to specified std::ostream.
  void print(std::ostream & out) const {
    out << Title << std::endl;
    out << Artist << std::endl;
    out << Year << std::endl;
  }
  // Method: read(std::istream & in).
  // Description: Reads data from std::istrem to populate all variables in class Song.
  void read(std::istream & in) {
    std::getline(in, Title);
    std::getline(in, Artist);
    in >> Year;
    in.get();
  }
  // Method: equal(const Song & other)
  // Description: Returns true if the receiver and the argument have the same title, artist and recording year
  bool equal(const Song & other) const {
    if (other.Title == Title && other.Artist == Artist && other.Year == Year)
      return true;
    return false;
  }
  // Method: less_than(const Song & other)
  // Description: returns true if the title of the first song is less than the title of the second song. In case the titles of the two songs are identical, the operator returns true if the artist of the first song is less than the artist of the second song. In case the titles and artists of the two songs are identical, the operator returns true if the first song was recorded before the second one. In all other cases, the operator returns false.
  bool less_than(const Song & other) const {
    if ((Title < other.Title) || (Title == other.Title && Artist < other.Artist) || (Title == other.Title && Artist == other.Artist && Year < other.Year)) {
      return true;
    } else {
      return false;
    }
  }
private:
  std::string Title, Artist;
  int Year;
};

int main() {
  Song s;
  std::cout << "Enter song 1 in the following order (Title, Artist, Year):" << std::endl;
  s.read(std::cin);
  std::cout << "Song 1 Details:" << std::endl;
  s.print(std::cout);
  std::cout << "----------" << std::endl;
  std::cout << "Enter song 2 in the following order (Title, Artist, Year):" << std::endl;
  Song t;
  t.read(std::cin);
  std::cout << "Song 2 Details:" << std::endl;
  t.print(std::cout);
  std::cout << "----------" << std::endl;
  std::cout << "Is song 1 less than song 2?" << std::endl;
  if (s.less_than(t)) {
    std::cout << "Yes.";
  } else {
    std::cout << "No";
  }
  std::cout << std::endl;
  std::cout << "----------" << std::endl;
  std::cout << "Is song 1 equal to song 2? " << std::endl;
  if (s.equal(t)) {
    std::cout << "Yes.";
  } else {
    std::cout << "No";
  }
  std::cout << std::endl;
}
