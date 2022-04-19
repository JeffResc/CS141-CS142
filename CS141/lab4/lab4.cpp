#include<iostream>
#include<string>

int main() {
	// Creates the 'n' variable in which the user input will be stored
	int n;
	
	// Prompts the user to input their number of choice
	std::cout << "Please enter a number to generate Fibonacci numbers and factorials: ";
	std::cin >> n;
	
	// Checks to ensure that the user has inputted a number greater than 0
	if (n > 0) {
		// Start the output so that we can append to it later
		std::cout << "The first " << n << " Fibonacci numbers are: 1 1";
		
		// Start generating the Fibonacci numbers, starting by declaring a string to store the Fibonacci numbers in
		std::string fibNums;
		int num1 = 1;
		int num2 = 1;
		for(int x = 3; x <= n; x++) {
			int newNum = num1 + num2;
			std::cout << " " << newNum;
			num1 = num2;
			num2 = newNum;
		}
		
		// Start generating the factorial
		int factorial = 1;
		for(int iteration = n; iteration > 0; iteration--) {
			factorial = factorial * iteration;
		}
		
		// Output the final information back to the user
		std::cout << ", and the factorial is " << factorial << "." << std::endl;
		
	} else if(n == 0) { // If the user enters 0, still state the factorial of 0
		std::cout << "ERROR: entered 0, cannot generate Fibonacci numbers, but the factorial of 0 is 1." << std::endl;
	} else { // If the user enters a negative number
		std::cout << "ERROR: entered " << n << ", cannot generate Fibonacci numbers, and cannot generate factorials for negative numbers." << std::endl;
	}

	// Return 0 as the exit code
	return 0;
}