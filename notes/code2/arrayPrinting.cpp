#include <iostream>

using int_array = int [4]; // C++11
// or typedef int int_array[4];

int main() {

	int ia[3][4] = { 
        	{1, 2, 3, 4}, 
	        {5, 6, 7, 8}, 
        	{9, 10, 11, 12} 
	};

	// pointer math
	for (int (*p)[4] = ia; p != ia + 3; ++p) 
		    for (int *q = *p; q != *p + 4; ++q) 
			std::cout << *q << ' ';
		std::cout << std::endl;

	// type alias
	for (int_array *p = ia; p != ia + 3; ++p) 
		for (int *q = *p; q != *p + 4; ++q) 
			std::cout << *q << ' ';
		std::cout << std::endl;

	// using auto
	for (auto p = ia; p != ia + 3; ++p) 
		for (auto q = *p; q != *p + 4; ++q) 
			std::cout << *q << ' ';
		std::cout << std::endl;

	// using iterators
	for (auto p = std::begin(ia); p != std::end(ia); ++p) 
		for (auto q = std::begin(*p); q != std::end(*p); ++q) 
			std::cout << *q << ' ';
		std::cout << std::endl;
}
