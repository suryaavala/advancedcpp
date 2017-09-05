#include <iostream>

// Returns a hash code based on an address
unsigned short hash(void *p) {
  unsigned long val = reinterpret_cast<unsigned long>(p);
  return ( unsigned short )(val ^ (val >> 16));
}

int main() {
  int a[20];
  for (int i = 0; i < 20; i++)
    std::cout << hash(a + i) << std::endl;
}

