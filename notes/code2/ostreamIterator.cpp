#include <iostream>
#include <vector>
#include <iterator>

int main() {
 std::vector<int> v{1, 2, 3, 4, 5};
 std::ostream_iterator<int> os(std::cout, " ");
 for (const auto &i : v)
   *os = i; // or *os++ = i;
}
