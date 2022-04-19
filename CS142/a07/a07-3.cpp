/*
  Jeffrey Rescignano <rescigjj@clarkson.edu>
  CS142 - Assignmenent 7, Part 3
  https://people.clarkson.edu/~alexis/CS142/Assignments/a07.pdf
*/

#include<string>
#include<iostream>
#include<fstream>
#include<map>

void read_books(std::map<std::string, int> & m, const std::string & file_name) {
  std::ifstream ifs;
  ifs.open(file_name.c_str());
  std::string title;
  std::string yearStr;
  int year;
  while (std::getline(ifs, title)) {
    std::getline(ifs, yearStr);
    year = std::stoi(yearStr);
    m.insert(std::make_pair(title, year));
  }
  ifs.close();
}

void print_recent(std::map<std::string, int> & m, const int & year) {
  for(const auto & book : m) {
    if (book.second > year)
      std::cout << book.first << std::endl;
  }
}

int main() {
  std::map<std::string, int> BookMap;

  read_books(BookMap, "BookFile.txt");

  const int recent = 2010;
  print_recent(BookMap, recent);
  return 0;
}
