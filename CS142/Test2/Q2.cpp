// Q2
#include<istream>
#include<vector>

template <typename T>
void read_lines(istream in, std::vector<T> v) {
  T line;
  v.clear();
  while(in >> line) {
    v.push_back(line)
  }
}
