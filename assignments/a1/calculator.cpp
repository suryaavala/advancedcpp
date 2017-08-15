#include <iostream>
#include <fstream>
#include <iomanip>

//include string and stack
#include <string>
#include <stack>

//include queue for reversing
#include <queue>

//include cmath for sqrt
#include <cmath>

//include string stream for double to string precision
#include <sstream>


//TODO Delete Typinfo after debugging
#include <typeinfo>
void print_stack(std::stack<std::string> c);
void print_queue(std::queue<std::string> c);
bool DEBUG = 0;

std::stack <std::string> calculate (std::stack <std::string> current_stack, std::string operation);



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
                                        if(DEBUG)
                                        {//TODO Delete cout
                                        std::cout << s << " = s here "<<  '\n';}

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
    else if (s != "repeat" && s != "endrepeat"){
      calc = calculate(calc, s);
    }
	}
	in.close();
}

void print_stack(std::stack<std::string> c) {
    while (!c.empty()) {
        std::cout<<c.top()<<" ";
        c.pop();
    }
    //std::cout << "\nreversed" << '\n';
}

void print_queue(std::queue<std::string> q) {
    while (!q.empty()) {
        std::cout<<q.front()<<" ";
        q.pop();
    }
    //std::cout << "\nreversed" << '\n';
}

std::stack <std::string> calculate (std::stack <std::string> current_stack, std::string operation) {
  if (operation == "add" || operation == "sub" || operation == "mult" || operation == "div") {
    std::string a, b;
    a = current_stack.top();
    current_stack.pop();
    b = current_stack.top();
    current_stack.pop();
    std::cout << a << " " << b << " " << operation << '\n';

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
    if (operation == "add") {
      if (a.find('.') != std::string::npos || b.find('.') != std::string::npos) {
          double n1 = std::stod(a);
          double n2 = std::stod(b);
          double ans = n1 + n2;

          std::cout << n1 << " + " << n2 << " = " << ans << '\n';

          current_stack.push(std::to_string(ans));
      }
      else if (operation == "add" ) {
        int n1 = std::stod(a);
        int n2 = std::stod(b);
        int ans = n1 + n2;

        std::cout << n1 << " + " << n2 << " = " << ans << '\n';

        current_stack.push(std::to_string(ans));
      }
    }

    else if (operation == "sub") {
      if (a.find('.') != std::string::npos || b.find('.') != std::string::npos) {
          double n1 = std::stod(a);
          double n2 = std::stod(b);
          double ans = n1 - n2;

          std::cout << n1 << " - " << n2 << " = " << ans << '\n';

          current_stack.push(std::to_string(ans));
      }
      else {
        int n1 = std::stod(a);
        int n2 = std::stod(b);
        int ans = n1 - n2;

        std::cout << n1 << " - " << n2 << " = " << ans << '\n';

        current_stack.push(std::to_string(ans));
      }
    }

    else if (operation == "mult") {
      if (a.find('.') != std::string::npos || b.find('.') != std::string::npos) {
          double n1 = std::stod(a);
          double n2 = std::stod(b);
          double ans = n1 * n2;

          std::cout << n1 << " * " << n2 << " = " << ans << '\n';

          current_stack.push(std::to_string(ans));
      }
      else {
        int n1 = std::stod(a);
        int n2 = std::stod(b);
        int ans = n1 * n2;

        std::cout << n1 << " * " << n2 << " = " << ans << '\n';

        current_stack.push(std::to_string(ans));
      }
    }

    else if (operation == "div") {
      if (a.find('.') != std::string::npos || b.find('.') != std::string::npos) {
          double n1 = std::stod(a);
          double n2 = std::stod(b);
          double ans = n1 / n2;

          std::cout << n1 << " / " << n2 << " = " << ans << '\n';

          current_stack.push(std::to_string(ans));
      }
      else {
        int n1 = std::stod(a);
        int n2 = std::stod(b);
        int ans = n1 / n2;

        std::cout << n1 << " / " << n2 << " = " << ans << '\n';

        current_stack.push(std::to_string(ans));
      }
    }



  }

  else if (operation == "sqrt") {
    std::string a;
    a = current_stack.top();
    current_stack.pop();
    std::cout << a << " " << operation << '\n';

    if (a.find('.') != std::string::npos) {

      double n1 = std::stod(a);
      double ans = sqrt(n1);
      std::cout << "sqrt " << n1 << " = " << ans << '\n';

      current_stack.push(std::to_string(ans));
    }

    else {

      int n1 = std::stoi(a);
      int ans = sqrt(n1);
      std::cout << "sqrt " << n1 << " = " << ans << '\n';

      current_stack.push(std::to_string(ans));
    }
  }

  //Pop
  else if (operation == "pop") {
    current_stack.pop();
  }

  //Reverse stack
  else if (operation == "reverse") {
                                if(DEBUG)
                                {  std::cout << "Current Stack before reversing: " << '\n';
                                  print_stack(current_stack);
                                  std::cout << "/* Reversing */" << '\n';}


    int elements_reversed = std::stoi(current_stack.top());
    current_stack.pop();
    std::queue <std::string> tmpcalc;

    while (!current_stack.empty() && elements_reversed != 0) {
      tmpcalc.push(current_stack.top());
      current_stack.pop();
      elements_reversed -= 1;
    }
                                if (DEBUG)
                                {//current_stack = tmpcalc;
                                std::cout << "Temp queue while reversing: " << '\n';
                                print_queue(tmpcalc);}

    while (!tmpcalc.empty()) {
      current_stack.push(tmpcalc.front());
      tmpcalc.pop();
    }
                                  if (DEBUG)
                                  {    std::cout << "Current Stack after reversing: " << '\n';
                                      print_stack(current_stack);
                                      std::cout << "/* message */" << '\n';}
  }

  return current_stack;
}
