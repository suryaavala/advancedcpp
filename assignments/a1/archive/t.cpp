#include <iostream>
#include <string>
#include <iomanip>
#include <string>
#include <sstream>

int main(int argc, char const *argv[]) {
  std::string c = "1.1";
  int a = std::stoi(c);
  double b = std::stod(c);

  std::cout << "a = " << a <<", b = " << b << ", c = " << c << " a/b = " <<a/b<<'\n';
  std::stringstream stream;
  //stream << std::fixed << std::setprecision(3) << a;


  //std::string x = stream.str();
  stream << std::fixed << std::setprecision(3) << b;
  std::string y = stream.str();

  std::cout << "x = " << " y = " << y << '\n';

  return 0;

}
