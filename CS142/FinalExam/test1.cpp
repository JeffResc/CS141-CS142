/*
  Jeffrey Rescignano
  CS142 - Test 1 Retake
*/

// Question 1A
// Abstraction is the process of seperating code into components that do different functions. Each component it usually a class.
// We use the analogy that each component is a box that you can speak to and get values in return, but you do not need to know
// the specifics on how the box works, but only what you tell it and what it returns.

// Question 1B
// A constructor initializes a class. A default constructor provides no information to the class when you initialize it, so it will
// usually either be a blank or default instance of that class. There are also other constructors that allow you to specify arguments
// while initializing the class, this can be handy for setting default values in it.

// Question 1C
// An input operator should return the stream for multiple reasons. For starters this allows for "while (stream >> word) {}" to read
// a stream word-by-word while also checking the stream's status automatically. This is also useful when passing the stream around
// multiple methods as each method will be able to get the status of the stream while reading it's input data.

// Question 2
class Product {
public:
  Product() : number(0), description("invalid"), price(-1) {};
  Product(const int & n, const std::string & d, const double & p) : number(n), description(d), price(p) {};
  const std::string & description() const {
    return description;
  }
  void set_price(const double & new_price) {
    price = new_price;
  }
  void print(ostream & out) const {
    out << number << ", " << description << " : $" << price << std::endl;
  }
  void operator>>(std::istream & in) {
    std::getline(in, number);
    std::getline(in, description);
    in >> price;
    in.get();
  }
  bool operator<(const Product & second) const {
    return (number < second.number);
  }
private:
  int number;
  std::string description;
  double price;
}

// Question 3
void strcpy(char dest[], const char & source[]) {
  for(int i = 0; i < source.size(); i++) {
    dest[i] = source[i];
  }
}
