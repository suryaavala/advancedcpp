#include <iostream>

int main() {
	std::string s("Hello World!");
	for (auto &c : s)	// Range loop, C++11, basically for each
		c = std::toupper(c);	// Also using auto...
	std::cout << s << std::endl; // HELLO WORLD!
}

