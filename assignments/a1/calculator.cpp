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
//void print_stack(std::stack<std::string> c);


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
  //  std::cout << s << isdigit(s[0])<<  '\n';

    if (isdigit(s[0])) {
      // if (s.find('.') != std::string::npos) {
      //   double n = std::stod(s);
      //   calc.push(n);
      // }
      // else {
      //   int n = std::stoi(s);
      //   calc.push(n);
      // }
      calc.push(s);
    }
    else if (s == "add" || s == "sub" || s == "mult" || s == "div") {
      std::string a, b;
      a = calc.top();
      calc.pop();
      b = calc.top();
      calc.pop();
      std::cout << a << " " << b << " " << s << '\n';

      // //Convertings to int or doubles
      // if (a.find('.') != std::string::npos || b.find('.') != std::string::npos) {
      //   int n1 = std::stod(a);
      //   int n2 = std::stod(b);
      // }
      // else {
      //   int n1 = std::stoi(a);
      //   int n2 = std::stoi(b);
      // }
      //std::cout << typeid(a).name() <<" "<< typeid(b).name()<< '\n';

      //Caclulation
      if (s == "add") {
        if (a.find('.') != std::string::npos || b.find('.') != std::string::npos) {
            double n1 = std::stod(a);
            double n2 = std::stod(b);
            double ans = n1 + n2;

            std::cout << n1 << " + " << n2 << " = " << ans << '\n';

            calc.push(std::to_string(ans));
        }
        else if (s == "add" ) {
          int n1 = std::stod(a);
          int n2 = std::stod(b);
          int ans = n1 + n2;

          std::cout << n1 << " + " << n2 << " = " << ans << '\n';

          calc.push(std::to_string(ans));
        }
      }

      else if (s == "sub") {
        if (a.find('.') != std::string::npos || b.find('.') != std::string::npos) {
            double n1 = std::stod(a);
            double n2 = std::stod(b);
            double ans = n1 - n2;

            std::cout << n1 << " - " << n2 << " = " << ans << '\n';

            calc.push(std::to_string(ans));
        }
        else {
          int n1 = std::stod(a);
          int n2 = std::stod(b);
          int ans = n1 - n2;

          std::cout << n1 << " - " << n2 << " = " << ans << '\n';

          calc.push(std::to_string(ans));
        }
      }

      else if (s == "mult") {
        if (a.find('.') != std::string::npos || b.find('.') != std::string::npos) {
            double n1 = std::stod(a);
            double n2 = std::stod(b);
            double ans = n1 * n2;

            std::cout << n1 << " * " << n2 << " = " << ans << '\n';

            calc.push(std::to_string(ans));
        }
        else {
          int n1 = std::stod(a);
          int n2 = std::stod(b);
          int ans = n1 * n2;

          std::cout << n1 << " * " << n2 << " = " << ans << '\n';

          calc.push(std::to_string(ans));
        }
      }

      else if (s == "div") {
        if (a.find('.') != std::string::npos || b.find('.') != std::string::npos) {
            double n1 = std::stod(a);
            double n2 = std::stod(b);
            double ans = n1 / n2;

            std::cout << n1 << " / " << n2 << " = " << ans << '\n';

            calc.push(std::to_string(ans));
        }
        else {
          int n1 = std::stod(a);
          int n2 = std::stod(b);
          int ans = n1 / n2;

          std::cout << n1 << " / " << n2 << " = " << ans << '\n';

          calc.push(std::to_string(ans));
        }
      }



    }

    else if (s == "sqrt") {
      std::string a;
      a = calc.top();
      calc.pop();
      std::cout << a << " " << s << '\n';

      if (a.find('.') != std::string::npos) {

        double n1 = std::stod(a);
        double ans = sqrt(n1);
        std::cout << "sqrt " << n1 << " = " << ans << '\n';

        calc.push(std::to_string(ans));
      }

      else {

        int n1 = std::stoi(a);
        int ans = sqrt(n1);
        std::cout << "sqrt " << n1 << " = " << ans << '\n';

        calc.push(std::to_string(ans));
      }
    }

    //Pop
    else if (s == "pop") {
      calc.pop();
    }

    //Reverse stack
    else if (s == "reverse") {
      //std::cout << calc << '\n';
      //print_stack(calc);

      std::stack <std::string> tmpcalc;

      while (!calc.empty()) {
        tmpcalc.push(calc.top());
        calc.pop();
      }
      calc = tmpcalc;

      //print_stack(calc);
      //::cout << calc << '\n';
    }
	}
	in.close();
}

// void print_stack(std::stack<std::string> c) {
//     while (!c.empty()) {
//         std::cout<<c.top()<<" ";
//         c.pop();
//     }
//     std::cout << "\nreversed" << '\n';
// }
