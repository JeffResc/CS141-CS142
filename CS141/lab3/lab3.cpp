#include<iostream>
#include <math.h>

int main()
{
	// Declare our variables
	float num1;
	float num2;
	float output;
	char operation;

	// Display the opening text
	std::cout << "Welcome to the Lab #3 calculator." << std::endl;
	std::cout << "This calculator supports the following functions: +, -, *, / and ^." << std::endl;
	std::cout << std::endl;
	std::cout << "Please use the following format when inputting your command:" << std::endl;
	std::cout << "<Number 1> <Operation> <Number 2>" << std::endl;
	std::cout << std::endl;

	// Ask the user for their input
	std::cin >> num1 >> operation >> num2;

	// Run the calculation
	if (operation == '+') {
		output = num1 + num2;
	} else if (operation == '-') {
		output = num1 - num2;
	} else if (operation == '*') {
		output = num1 * num2;
	} else if (operation == '/') {
		output = num1 / num2;
	} else if (operation == '^') {
		output = pow(num1, num2);
	}

	// Return the calculation to the user
	if (output) {
		std::cout << num1 << " " << operation << " " << num2 << " = " << output << std::endl;
	} else {
		std::cout << "Sorry, but the operation entered used isn't supported" << std::endl;
	}

	// Return 0 as the exit code
	return 0;
}
