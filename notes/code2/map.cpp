#include <iostream>
#include <string>
#include <map>

int main() {
  std::map<std::string, double> m;
  std::pair<std::string, double> p1("bat", 14.75);
  std::pair<std::string, double> p2("cat", 10.157);
  std::pair<std::string, double> p3("dog", 43.5);
  m.insert(p1); 
  m.insert(p2); 
  m.insert(p3);

  for(auto mit = m.begin(); mit!=m.end(); ++mit)
    std::cout << mit->first << ' ' << mit->second << std::endl;
}

