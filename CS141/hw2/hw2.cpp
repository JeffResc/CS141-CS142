#include<iostream>
#include<string>

int main() {
	// Declare our variables
	float num1;
	float num2;
	float output;
	std::string operation;

	// Display the opening text
	std::cout << "Welcome to the Homework #2 calculator." << std::endl;
	std::cout << "This calculator supports the following functions: + (plus), - (minus), * (multiply), and / (divide)." << std::endl;

  while(true) {
    std::cout << std::endl << "Please use the following format when inputting your command:" << std::endl;
  	std::cout << "<Number 1> <Operation> <Number 2>" << std::endl;
  	std::cout << std::endl;

  	// Ask the user for their input
    std::cin >> num1 >> operation >> num2;

    // See if we should exit and if true, exit
    if ((num1 == -1 && num2 == -1 && operation == "quit") || (num1 == -1 && num2 == -1 && operation == "x")) {
      std::cout << "Exiting..." << std::endl;
      return 0;
    }

  	// Run the calculation
  	if (operation == "+" || operation == "plus") {
  		std::cout << "Result of " << num1 << " " << operation << " " << num2 << " is " << num1+num2 << std::endl;
  	} else if (operation == "-") {
  		std::cout << "Result of " << num1 << " " << operation << " " << num2 << " is " << num1-num2 << std::endl;
  	} else if (operation == "*") {
  		std::cout << "Result of " << num1 << " " << operation << " " << num2 << " is " << num1*num2 << std::endl;
  	} else if (operation == "/") {
      if (num2 == 0) {
        std::cout << "Cannot divide by zero." << std::endl;
      } else {
        std::cout << "Result of " << num1 << " " << operation << " " << num2 << " is " << num1/num2 << std::endl;
      }
  	} else {
      std::cout << "Sorry, but the operation entered used isn't supported" << std::endl;
    }
  }
}
