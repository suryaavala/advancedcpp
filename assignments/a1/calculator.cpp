#include <iostream>
#include <fstream>
#include <iomanip>

//include string and stack
#include <string>
#include <stack>

//include queue for reversing the stack and capturing repeat calculations
#include <queue>

//include cmath for sqrt
#include <cmath>

//include string stream for precision during double to string conversion
#include <sstream>


//Functions for calculations and repeat (explained during function definitions)
std::stack <std::string> calculate (std::stack <std::string> current_stack, std::string operation);
std::stack <std::string> enrepeat (std::stack <std::string> current_stack, std::queue <std::string> rep_queue);



int main(int argc, char* argv[]) {

	// setup the print out format for the precision required.
	std::cout.setf(std::ios::fixed,std::ios::floatfield);
	std::cout.precision(3);

	// open the file for reading
	std::ifstream in;
	in.open(argv[1]);

	// string to be read into
	std::string s;

  //  Claculator stack, which stores the numbers(inputs and answers) to be operated on
  std::stack <std::string> calc;

  //Repeat queue which stores the commands inputed between repeat and end repeat
  std::queue <std::string> rep;

  //Boolean to check if we are in repeat mode or normal operational mode
  //When in Repeat mode, all the inputs are stored and they are only executed after the "endrepeat" command
  //Default non-repeat/operational mode
  bool rep_mode = 0;


	// read the file while we have input.
	while (in >> s) {

    //Check for if s is a valid number and the program is not in repeat mode (repeat mode as defined in line 44)
    //A number is valid when either:
    //1. It is a digit, example: 1, 66, 190, 4.5
    //2. Starts with "-", example: -1, -56, -1.1, -8.4  or
    //3. Starts with ".", example: .1, .094
    if ((isdigit(s[0]) || !s.compare(0,1,"-") || !s.compare(0,1,".")) && !rep_mode) {

      //If s is a double then push it to calc stack as string with proper precision, example: 16.0 will be pushed as 16.000
      if (s.find('.') != std::string::npos) {
        double n = std::stod(s);
        //Precision is acheived with sstream manipulations
        std::stringstream s_stream;
        s_stream << std::fixed << std::setprecision(3) << n;
        s = s_stream.str();
      }
      calc.push(s);
    }
    //If s neither repeat nor endrepeat and the program is not in repeat mode, then go ahead and perform the calculation
    else if (s != "repeat" && s != "endrepeat" && !rep_mode){
      calc = calculate(calc, s);
    }
    //If s is repeat or the program is not in repeat mode and s is not endrepeat (to avoid coming here during endrepeat statement)
    else if (s == "repeat" || (rep_mode && s != "endrepeat")) {
      //change the program to repeat mode
      rep_mode = 1;

      //Push the commands (other than "repeat" command itself) into rep queue
      if (s != "repeat") {
        rep.push(s);
      }
    }
    //If s is endrepeat the program is in repeat mode, then perform calculations where were being captured in rep queue as per the specs
    //endrepeat is ignored if a repeat is not issued as one of the previous commands
    else if (s == "endrepeat" && rep_mode) {

      calc = enrepeat(calc, rep);

      //cleaning/emptying rep queue and changing the program to non-repeat mode
      rep = std::queue <std::string>();
      rep_mode = 0;
    }
	}
	in.close();
}

//calculate function which is called when the perform the following operations:
// add, sub, mult, div, sqrt, pop, reverse
//Takes the current stack as an input
//Performs the requested operation
//prints out the neccessary outputs
//Modifies the stack as needed during the operations
//And returns the modified stack
std::stack <std::string> calculate (std::stack <std::string> current_stack, std::string operation) {

  //commands which require two pops (two numbers) in order to be executed
  if (operation == "add" || operation == "sub" || operation == "mult" || operation == "div") {

    //Popping the last two elements from the stack
    //Stack throws a seg fault and the program will be terminated if these operations are performed on a stack with size less than 2
    std::string a, b;
    a = current_stack.top();
    current_stack.pop();
    b = current_stack.top();
    current_stack.pop();

    //All these four operations are performed in the following order:
    //1. If either of the numbers are doubles then
      //1.1 initialise two temporary double variables by poping (& convert) last two elements on the stack
      //1.2 perform the operation, which results in a double as an answer
      //1.3 output the computation
      //1.4 convert the ans from double to ans_str with a precision of 3
      //1.5 push ans_str back to the stack
    //2. If neither of the numbers are doubles then
      //2.1 initialise two temporary int variables by poping (& converting) last two elements on the stack
      //2.2 perform the operation, which results in an int as an answer
      //2.3 output the computation
      //2.4 convert int ans to srting and push it to stack

    //addition
    if (operation == "add") {
      if (a.find('.') != std::string::npos || b.find('.') != std::string::npos) {
          double n1 = std::stod(a);
          double n2 = std::stod(b);
          double ans = n1 + n2;

          //Outputs are strings a & b instead of n1 and n2 as per the spec
          std::cout << a << " + " << b << " = " << ans << '\n';

          //Double to string with precision(3) then push answer back to stack
          std::stringstream ans_stream;
          ans_stream << std::fixed << std::setprecision(3) << ans;
          std::string ans_str = ans_stream.str();
          current_stack.push(ans_str);
      }
      else if (operation == "add" ) {
        int n1 = std::stoi(a);
        int n2 = std::stoi(b);
        int ans = n1 + n2;

        std::cout << a << " + " << b << " = " << ans << '\n';

        current_stack.push(std::to_string(ans));
      }
    }

    //subtraction
    else if (operation == "sub") {
      if (a.find('.') != std::string::npos || b.find('.') != std::string::npos) {
          double n1 = std::stod(a);
          double n2 = std::stod(b);
          double ans = n1 - n2;

          std::cout << a << " - " << b << " = " << ans << '\n';


          //Double to string with precision(3) then push to stack
          std::stringstream ans_stream;
          ans_stream << std::fixed << std::setprecision(3) << ans;
          std::string ans_str = ans_stream.str();
          current_stack.push(ans_str);
      }
      else {
        int n1 = std::stoi(a);
        int n2 = std::stoi(b);
        int ans = n1 - n2;

        std::cout << a << " - " << b << " = " << ans << '\n';

        current_stack.push(std::to_string(ans));
      }
    }

    //multiplication
    else if (operation == "mult") {
      if (a.find('.') != std::string::npos || b.find('.') != std::string::npos) {
          double n1 = std::stod(a);
          double n2 = std::stod(b);
          double ans = n1 * n2;

          std::cout << a << " * " << b << " = " << ans << '\n';

          //Double to string with precision(3) then push to stack
          std::stringstream ans_stream;
          ans_stream << std::fixed << std::setprecision(3) << ans;
          std::string ans_str = ans_stream.str();
          current_stack.push(ans_str);
          //current_stack.push(std::to_string(ans));
      }
      else {
        int n1 = std::stoi(a);
        int n2 = std::stoi(b);
        int ans = n1 * n2;

        std::cout << a << " * " << b << " = " << ans << '\n';

        current_stack.push(std::to_string(ans));
      }
    }

    //division
    else if (operation == "div") {
      if (a.find('.') != std::string::npos || b.find('.') != std::string::npos) {
          double n1 = std::stod(a);
          double n2 = std::stod(b);
          double ans = n1 / n2;

          std::cout << a << " / " << b << " = " << ans << '\n';

          //Double to string with precision(3) then push to stack
          std::stringstream ans_stream;
          ans_stream << std::fixed << std::setprecision(3) << ans;
          std::string ans_str = ans_stream.str();
          current_stack.push(ans_str);
          //current_stack.push(std::to_string(ans));
      }
      else {
        int n1 = std::stoi(a);
        int n2 = std::stoi(b);
        int ans = n1 / n2;

        std::cout << a << " / " << b << " = " << ans << '\n';

        current_stack.push(std::to_string(ans));
      }
    }

  }

  //Square root, requires only one pop
  else if (operation == "sqrt") {
    //Pop the most recent element
    //If the stack is not of appropriate size, then a seg fault is thrown as explained in line 111
    std::string a;
    a = current_stack.top();
    current_stack.pop();

    //checks if the popped element is a double or int and performs the computation, prints and stores the result accordingly (similiar to how addition and others are done)
    if (a.find('.') != std::string::npos) {

      double n1 = std::stod(a);
      double ans = sqrt(n1);
      std::cout << "sqrt " << a << " = " << ans << '\n';

      //Double to string with precision(3) then push to stack
      std::stringstream ans_stream;
      ans_stream << std::fixed << std::setprecision(3) << ans;
      std::string ans_str = ans_stream.str();
      current_stack.push(ans_str);
      //current_stack.push(std::to_string(ans));
    }

    else {

      int n1 = std::stoi(a);
      int ans = sqrt(n1);
      std::cout << "sqrt " << a << " = " << ans << '\n';

      current_stack.push(std::to_string(ans));
    }
  }

  //Pop
  //Deletes the most recent element from the stack
  else if (operation == "pop") {
    current_stack.pop();
  }

  //Reverse stack
  //1.1 Pops the most recent element from the stack, lets call it "elements_reversed"
  //1.2 Reverse the most recent "elements_reversed" number of elements in the stack
  //During reversal poped elements are stored in a temporary queue
  //Example: stack = 1,2,3,4,5 and elements_reversed = 2
  //Then 5,4 are removed from the stack in that order and stored in tempcalc = 5,4; stack = 1,2,3
  //Elements in tempcalc (from the front) are added back in the stack in that order
  //Then stack becomes 1,2,3,5,4 (reversing the last two elements)

  else if (operation == "reverse") {

    int elements_reversed = std::stoi(current_stack.top());
    current_stack.pop();
    std::queue <std::string> tmpcalc;

    while (!current_stack.empty() && elements_reversed != 0) {
      tmpcalc.push(current_stack.top());
      current_stack.pop();
      elements_reversed -= 1;
    }

    while (!tmpcalc.empty()) {
      current_stack.push(tmpcalc.front());
      tmpcalc.pop();
    }

  }

  //function returns the modified stack back
  return current_stack;
}

//enrepeat function which is called by main when it sees endrepeat command
//enrepeat takes the calc stack and rep_queue as its arguments
  //calc stack is the Claculator stack, which has stored the numbers(inputs and answers) to be operated on
  //rep queue is the Repeat queue which has stored the commands/numbers inputed between repeat and end repeat
//executes(by calling calcute fucntions)/repeats the commands on the repeat queue as desired/per spec
//modifies the current stack accordingly
//and returns the modified stack in the end
std::stack <std::string> enrepeat (std::stack <std::string> current_stack, std::queue <std::string> rep_queue){

  //Removes the most recent number on the calculator stack and stores in nb_repeats
  //nb_repeats is the number of times the commands on the repeat queue are executed
  int nb_repeats = std::stoi(current_stack.top());
  current_stack.pop();

  while (nb_repeats) {
    //Repeat commands from rep_queue are temporarily copied to temp_rep_queue
    std::queue <std::string> temp_rep_queue = rep_queue;

    //Rep stack for nested repeats
    //Nested repeats are executed recursively
    std::queue <std::string> nested_rep;
    bool nested_rep_mode = 0;

    //Execute commands from the front of temp_rep_queue until it is exhausted
    while (!temp_rep_queue.empty()) {

      std::string s = temp_rep_queue.front();

      //similar to what main has done with the inputs from the file, except here we are considering the inputs from the repeats queue as commands
      if ((isdigit(s[0]) || !s.compare(0,1,"-") || !s.compare(0,1,"."))  && !nested_rep_mode) {

        //If s is a double then push it as string with proper precision
        if (s.find('.') != std::string::npos) {
          double n = std::stod(s);
          std::stringstream s_stream;
          s_stream << std::fixed << std::setprecision(3) << n;
          s = s_stream.str();
        }
        current_stack.push(s);
      }
      //if the commands are non repeats then they are executed by calling calculate function
      else if (s != "repeat" && s != "endrepeat" && !nested_rep_mode){
        current_stack = calculate(current_stack, s);
      }
      //if this function sees another repeat, then it goes into nested repeat mode recursively
      else if (s == "repeat" || (nested_rep_mode && s != "endrepeat")) {
        nested_rep_mode = 1;
        nested_rep.push(s);

      }
      else if (s == "endrepeat") {
        //recursively executes nested repeats
        current_stack = enrepeat(current_stack, nested_rep);

        //Cleaning nested_rep and nested_rep_mode
        nested_rep = std::queue <std::string>();
        nested_rep_mode = 0;
      }

      temp_rep_queue.pop();
    }

    //reducing the number of repeats every time all the commands on repeat queue are executed
    nb_repeats -= 1;
  }

  //returns the modified stack
  return current_stack;
}
