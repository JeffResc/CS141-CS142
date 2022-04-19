// Q5

template <typename T, typename List>
void insert_back(const int & n, T e, List & ls) {
  for (int i = 0; i < n; i++) {
    ls.push_back(e);
  }
}
