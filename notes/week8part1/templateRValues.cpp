#include<iostream>

template <typename T> void foo(T &&a) { }

class X {};
const X goo() { return X(); }

int main() {
  foo(1);                  // rvalue
                           // instantiate foo(int&&)

  foo(goo());              // const rvalue
                           // instantiate foo(const X&&)
  int j = 1;        
  foo(j);                  // lvalue
                           // instantiate foo(int&)
  const int &k = 1;
  foo(k);                  // const lvalue
                           // instantiate foo(const int&)
}
