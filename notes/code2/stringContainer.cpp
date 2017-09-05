#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

int main() {
  std::vector<int> v{3, 2, 1};
  std::string s("string");

  std::sort(v.begin(), v.end());
  std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  std::sort(s.begin(), s.end());
  std::copy(s.begin(), s.end(), std::ostream_iterator<char>(std::cout, " "));
  std::cout << std::endl;
}
