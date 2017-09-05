#include <iostream>
#include <string>

int main() {
  std::string name, greeting;

  std::cout << "Please enter your first name: ";
  while(std::cin >> name) {
      greeting = "Hello, " + name + "!";
      std::cout << greeting << std::endl << std::endl;
      std::cout << "Please enter your first name: ";
  }
  
  return 0;
}
