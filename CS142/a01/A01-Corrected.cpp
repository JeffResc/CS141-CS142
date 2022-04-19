#include<iostream>
#include<fstream>
#include<istream>
#include<string>

class Song {
  friend void print(const Song & s, std::ostream & out);
  friend void read(Song & s,std::istream & in);
private:
  std::string Title, Artist;
  int Year;
};

// Function: print(const Song & s, std::ostream & out).
// Description: Prints all variables in class Song to specified std::ostream.
void print(const Song & s, std::ostream & out) {
  out << s.Title << std::endl;
  out << s.Artist << std::endl;
  out << s.Year << std::endl;
}
// Function: read(Song & s,std::istream & in).
// Description: Reads data from std::istrem to populate all variables in class Song.
void read(Song & s,std::istream & in) {
  std::getline(in, s.Title);
  std::getline(in, s.Artist);
  in >> s.Year;
  in.get();
}

int main() {
  Song s;
  read(s, std::cin);
  print(s, std::cout);
  return 0;
}
