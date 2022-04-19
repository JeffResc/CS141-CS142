// Q3

#include<vector>
#include<algorithm>
#include<iostream>
int main() {
  std::vector<int> v = {1, 16, 28, 39, 47, 54, 62, 76, 84, 99};
  auto itr = std::find(v.begin(), v.end(), 39);
  std::cout << *itr << std::endl; // Outputs 39 as that is where the iterator points to
}
