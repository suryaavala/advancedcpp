#include <iostream>
#include <fstream>

namespace cs6771 {
	void order3(int *a, int *b, int *c) {
		if (*a < *c) {
			int t = *a;
			*a = *c;
			*c = t;
		}
		if (*a < *b) {
			int t = *a;
			*a = *b;
			*b = t;
		}
		if (*b < *c) {
			int t = *b;
			*b = *c;
			*c = t;
		}
	}
}

int main() {
	std::cout << "Enter three ints: ";
	int i, j, k;
	std::cin >> i >> j >> k;
	cs6771::order3(&i,&j,&k);
	std::ofstream outStream;
	outStream.open("sort.txt");
	outStream << i << " " << j << " " << k << " ";
	outStream.close();
	std::cout << i << " " << j << " " << k << std::endl;
}
