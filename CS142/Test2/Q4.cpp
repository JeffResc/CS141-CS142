// Q4

class IsLongerThan {
  int n;
public:
  IsLongerThan(const int & n) : n(n) {};
  inline bool operator()(const std::string & s) const {
    return (s.length() > n);
  }
};
