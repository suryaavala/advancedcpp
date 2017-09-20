#include <iostream>

void foo(const std::string &a) { } 

const std::string goo() { return "C++"; }
	
int main() {
  foo("C++");               // \alert{// rvalue}
  foo(goo());                 //  \alert{// const rvalue}
  std::string j = "C++";
  foo(j);                   //  \alert{// lvalue}
  const std::string &k = "C++";
  foo(k);                   //  \alert{// const lvalue}
}
