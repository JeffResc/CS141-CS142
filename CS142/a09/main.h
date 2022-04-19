/*
  Jeffrey Rescignano <rescigjj@clarkson.edu>
  CS142 - Assignmenent 9, main.h
  https://people.clarkson.edu/~alexis/CS142/Assignments/a09.pdf
*/

#include <vector>

template<class T>
class Queue {
  std::vector<T> v = {};
public:
  Queue() {}
  Queue(std::vector<T> *v2) : v(v2) {}
  inline int size() {
    return v.size();
  }
  inline bool empty() {
    return (v.size() == 0);
  }
  inline T front() {
    return v[0];
  }
  inline T pop() {
    T fr = v[0];
    v.erase(v.begin());
    return fr;
  }
  inline T push(T i) {
    v.push_back(i);
    return i;
  }
  inline void clear() {
    v.clear();
  }
  Queue operator=(std::vector<T> *v2) {
    return (v = v2);
  }
};
