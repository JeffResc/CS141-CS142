#include<iostream>
#include<fstream>
#include<istream>
#include<string>

class Song {
public:
  // Function: print(std::ostream & out).
  // Description: Prints all variables in class Song to specified std::ostream.
  void print(std::ostream & out) {
    out << Title << std::endl;
    out << Artist << std::endl;
    out << Year << std::endl;
  }
  // Function: read(std::istream & in).
  // Description: Reads data from std::istrem to populate all variables in class Song.
  void read(std::istream & in) {
    std::getline(in, Title);
    std::getline(in, Artist);
    std::getline(in, Year);
  }
private:
  std::string Title, Artist, Year;
};

int main() {
  Song s;
  s.read(std::cin);
  s.print(std::cout);
}
