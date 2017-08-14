#include <iostream>
#include <fstream>
#include <iomanip>

//include string and stack
#include <string>
#include <stack>

//include cmath for sqrt
#include <cmath>


//TODO Delete Typinfo after debugging
#include <typeinfo>

int main(int argc, char* argv[]) {

	// setup the print out format for the precision required.
	std::cout.setf(std::ios::fixed,std::ios::floatfield);
	std::cout.precision(3);

	// open the file for reading
	std::ifstream in;
	in.open(argv[1]);

	// string to be read into
	std::string s;

  //  Claculator stack
  std::stack <std::string> calc;
  //TODO Stack functions
  // empty() – Returns whether the stack is empty
  // size() – Returns the size of the stack
  // top() – Returns a reference to the top most element of the stack
  // push(g) – Adds the element ‘g’ at the top of the stack
  // pop() – Deletes the top most element of the stack


	// read the file while we have input.
	while (in >> s) {

    //TODO Delete cout
    std::cout << s << isdigit(s[0])<<  '\n';

    if (isdigit(s[0])) {
      calc.push(s);
    }
    else {
      std::string a, b;
      a = calc.top();
      calc.pop();
      b = calc.top();
      calc.pop();
      std::cout << a << " " << b << " " << s << '\n';
    }
	}
	in.close();
}
