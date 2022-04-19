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

  /* Method: operator<<(std::ostream & out).
    Description: Prints all variables in class Song to specified std::ostream. */
  inline void operator<<(std::ostream & out) const {
    out << Title << std::endl;
    out << Artist << std::endl;
    out << Year << std::endl;
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

bool operator>>(std::istream & in);
bool operator==(const Song & other);
bool operator<(const Song & other);

int main() {
  // Collect details of song 1 using the >> operator method.
  Song s1;
  std::cout << "Enter song 1 details in the following order (Title, Artist, Year):" << std::endl;
  std::cin >> s1;

  // Collect details of song 2 using the set_title, set_artist and set_year methods.
  Song s2;
  std::string title;
  std::string artist;
  int year;
  std::cout << "Enter song 2 details in the following order (Title, Artist, Year):" << std::endl;
  std::getline(std::cin, title);
  std::getline(std::cin, artist);
  std::cin >> year;
  std::cin.get();

  // Pass the variables to the various set_ methods.
  s2.set_title(title);
  s2.set_artist(artist);
  s2.set_year(year);

  // Create song 3 and pass the variables to the set method. We will later compare songs 2 and 3 to ensure that the same values were set.
  Song s3;
  s3.set(title, artist, year);

  // Print song 1 using the << operator.
  std::cout << "Song 1 details:" << std::endl;
  s1 << std::cout;

  // Print song 2 manually using the methods
  std::cout << "Song 2 details:" << std::endl;
  std::cout << s2.title() << std::endl;
  std::cout << s2.artist() << std::endl;
  std::cout << s2.year() << std::endl;

  // Print song 3 using the << operator.
  std::cout << "Song 3 details:" << std::endl;
  s3 << std::cout;

  // Set the test variables
  bool t;
  std::string a;

  // Test if song 1 is less than song 2
  t = s1 < s2;
  if (t) {
    a = "Yes";
  } else {
    a = "No";
  }
  std::cout << "Is song 1 less than song 2? " << a << std::endl;

  // Test if song 2 is equal to song 3
  t = s2 == s3;
  if (t) {
    a = "Yes";
  } else {
    a = "No";
  }
  std::cout << "Is song 2 equal to song 3? " << a << std::endl;
}

/* Function: Song::operator>>(std::istream & in).
   Description: Reads data from std::istrem to populate all variables in class Song. */
bool operator>>(std::istream & in) {
  std::getline(in, Title);
  std::getline(in, Artist);
  in >> Year;
  in.get();
}
/* Function: Song::operator==(const Song & other)
   Description: Returns true if the receiver and the argument have the same title, artist and recording year */
bool operator==(const Song & other) const {
  if (other.Title == Title && other.Artist == Artist && other.Year == Year)
    return true;
  return false;
}
/* Function: Song::operator<(const Song & other)
   Description: returns true if the title of the first song is less than the title of the second song. In case the titles of the two songs are identical, the operator returns true if the artist of the first song is less than the artist of the second song. In case the titles and artists of the two songs are identical, the operator returns true if the first song was recorded before the second one. In all other cases, the operator returns false. */
bool operator<(const Song & other) const {
  if ((Title < other.Title) || (Title == other.Title && Artist < other.Artist) || (Title == other.Title && Artist == other.Artist && Year < other.Year)) {
    return true;
  } else {
    return false;
  }
}
