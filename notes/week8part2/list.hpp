#ifndef LIST_HPP
#define LIST_HPP

#include "list_iterator.hpp"

template <typename T> class List {
public:
 friend class List_Iterator<T>;
 typedef List_Iterator<T> iterator;

  List() : head_(nullptr), tail_(nullptr) {}
  ~List() { delete head_; }

  bool isEmpty() const { return head_ == nullptr;  }
  void push_back(const T&);
  iterator begin() { return iterator(head_); }
  iterator end() { return iterator(nullptr); }  
                                                
private:
  struct Node {
    Node(const T& t, Node *next) : elem_(t), next_(next) {}
    ~Node() { 
       delete next_; 
    };
    T elem_;
    Node *next_;
  };
  Node *head_, *tail_;
};

template <typename T> 
void List<T>::push_back(const T& elem) {
  Node *newNode = new Node(elem, nullptr);
  if (!head_) 
    head_ = newNode;
  else
    tail_->next_ = newNode;
  tail_ = newNode;
}
// add more member functions here

#endif
