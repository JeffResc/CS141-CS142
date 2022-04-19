/*
  Jeffrey Rescignano <rescigjj@clarkson.edu>
  CS142 - Assignmenent 9, main.cpp
  https://people.clarkson.edu/~alexis/CS142/Assignments/a09.pdf
*/

#include "main.h"
#include<string>
#include<iostream>

int main() {
  Queue<std::string> q;
  q.push("Alexis");
  q.push("Jeff");
  std::cout << "Current size is " << q.size() << std::endl;
  std::cout << q.front() << " is at the front of the queue" << std::endl;
  std::cout << "Removing " << q.pop() << " from the queue" << std::endl;
  q.clear();
  std::cout << "Is the queue empty now? " << q.empty() << std::endl;
}
