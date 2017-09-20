#include <iostream>
#include <vector>

class Blob {
  std::vector<std::string> _v;
public:
   // variadic templated constructor
   template<typename... Args>
   Blob(Args&&... args) : _v(std::forward<Args>(args)...) {  }  
};
 
int main(void) {
  const char * shapes[3] = { "Circle", "Triangle", "Square" };
	   
  Blob b1(10, "C++11");  // uses vector's fill constructor
  Blob b2(shapes, shapes+3); // uses vector's range constructor
}
