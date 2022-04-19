/*
  Jeffrey Rescignano
  CS142 - Test 2 Retake
*/

// Question 1A
// Incremental software development allows you to have time to discuss with the client
// how you are doing building the piece of software. If the client does not like how
// one of the main components operate and many other components are dependent on it,
// knowing this information as soon as possible will be helpful.

// Question 1B
// A function object is also known as a functor. It is an object that acts as a function
// that we implemented by using them in algorithms. This allows your function object to
// have access to multiple variables (instead of just one argument) when generating it's
// return statement.

// Question 2
void increment_all(std::vector<int> v) {
  for(int i = 0; i < v.size(); i++) {
    v[i]++;
  }
}

// Question 3
template <typename Iterator, typename T>
void replace(Iterator *start, Iterator *stop, const T & x, const T & y) {
  for(Iterator itr = start; itr != stop; itr++) {
    if (*itr == x)
      *itr = y;
  }
}

// Question 4
template <typename Iterator, class UnaryPredicate>
Iterator find_if(Iterator start, Iterator stop, UnaryPredicate condition) {
  for (Iterator itr = start; itr != stop; itr++) {
    if (condition(*itr))
      return itr;
  }
  return stop;
}

// Question 5
void read_lines(istream & in, list & ls) {
  std::string str;
  ls.clear();
  int i = 0;
  while (std::getline(in, str)) {
    ls[i] = str;
    i++;
  }
}

// Question 6A
using ProductMap = std::map<int, double>;

// Question 6B
void read_products(ProductMap & m, const char & file_name[]) {
  std::ifstream ifs;
  ifs.open(file_name);
  int number;
  double price;
  std::string priceStr;
  while (std::getline(ifs, number)) {
    std::getline(ifs, priceStr);
    price = std::stod(priceStr);
    m.insert(std::make_pair(number, price));
  }
  ifs.close();
}

void print_cheap_products(ProductMap & m, const double & price) {
  for(const auto & product : m) {
    if (product.second < price)
      std::cout << product.first << std::endl;
    }
}
