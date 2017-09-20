#include <iostream>

template <typename T> struct is_ptr {
  static const bool val = false;
};

template <typename T> struct is_ptr<T*> { 
  static const bool val = true;
};

int main() {
  std::cout << is_ptr<int*>::val << std::endl;
  std::cout << is_ptr<int>::val << std::endl;
}
