/*
  Jeffrey Rescignano
  CS142 - Final Exam
*/

// Question 1A
// An interaction diagram shows how the different components of a program interact with each other internally. For instance, it would show how each class interacts with other classes
// and creates new insances of that class. It would also show each method that was called for a class.

// Question 1B
// In the case of dynamically allocated arrays, the new operator returns a pointer to the memory location of the first element in the array.

// Question 2
class Vector {
public:
  inline ~Vector() {
    for(auto i = buffer_; i < buffer_+size_; i++) {
      delete buffer_[i];
    }
  }
private:
  T ∗ buffer_;
  int size_;
}

// Question 3
class Vector {
public:
  template <class T>
  iterator insert(const_iterator const_itr, const T & e) {
    *const_itr = e;
  }
}

// Question 4
class List {
public:
  template <typename T>
  List(initializer_list<T> init_list) {
    head_node_ = new ListNode<T>;
    size_ = init_list.size();
    for(auto itr = init_list.begin(); itr < init_list.end(); itr++) {
      head_node_->next = *itr;
    }
  }
private:
  ListNode<T> ∗ head_node_;
  int size_;
}

class ListNode {
private:
  T element;
  ListNode<T> ∗ next;
  ListNode<T> ∗ previous;
}

// Question 5
class List {
public:
  pop_back() {
    auto last_in_list_ = head_node_->previous;
    auto new_last_ = last_in_list_->previous;
    new_last_->next = head_node_;
    head_node_->previous = new_last_;
    delete last_in_list_;
    size--;
  }
private:
  ListNode<T> ∗ head_node_;
  int size_;
}

// Question 6
template <typename Iterator>
void add_to_all(Iterator *begin, int start, int stop) {
  for(Iterator itr = begin+start; itr != begin+end; itr++) {
    *itr++;
  }
}

// Question 7

/*
  NOTE:
  This is not fully working, I ran out of time on it,
  I've commented what I was planning on doing with it.
*/

#include<iostream>
#include<tgmath.h>

void mergeArrays(int arr[], int start, int middle, int stop, int fs) {
  int newArrLength = (stop - middle) + (middle - start);
  if (newArrLength > 1) {
    //std::cout << "-----" << std::endl;
    int *tmpNewArr = new int [newArrLength];
    int *newArr = new int [newArrLength];
    int j = 0;
    for(int i = start; i < middle; i++ && j++) {
      newArr[j] = tmpNewArr[i];
    }
    for(int i = middle; i < stop; i++ && j++) {
      newArr[j] = tmpNewArr[i];
    }
    while(j > 0) {
      int min;
      // Find min and append to newArr until tmpNewArr is empty and
      // all values in tmpNewArr are in newArr, but sorted from min to max.
      // Then, find a way to pass the newArr back to mergeSort so it can use
      // it in future iterations
    }
  }
  for(int i = 0; i < fs; i++) {
    if (i == start)
      std::cout << '[';
    else
      std::cout << ' ';
    if (i == middle)
      std::cout << "][";
    else
      std::cout << "  ";
    if (i == stop)
      std::cout << ']';
    else
      std::cout << ' ';
    std::cout << arr[i];
  }
  std::cout << std::endl;
}

void mergeSort(int arr[], int start, int stop, int fs) {
  if (start < stop) {
    int middle = floor((start + stop) / 2);
    mergeSort(arr, start, middle, fs);
    mergeSort(arr, middle + 1, stop, fs);
    mergeArrays(arr, start, middle, stop, fs);
  }
}

int main() {
  int arr[8] = {53, 62, 91, 15, 72, 48, 32, 27};
  mergeSort(arr, 0, (sizeof(arr) / sizeof(int)) - 1, (sizeof(arr) / sizeof(int)) - 1);
}
