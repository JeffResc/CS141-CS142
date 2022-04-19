#include<iostream>
#include<string>

std::string productName;
int numOfValidPrices;
float minValue;
float maxValue;
float average;
float validPrices[10];
float prices[10];
float userInput;

int main() {
	// Start the program
	std::cout << "Welcome to the price finder program." << std::endl;

	// Make a continous loop until it is broken on line 26
	while(true) {
		// Prompt the user to enter a product name
		std::cout << "Enter a product name: ";
		std::cin >> productName;

		// Break the while loop from line 18 if the user enters "DONE"
		if (productName == "DONE") {
			std::cout << "Thank you for using the program!";
			break;
		}

		// Take up to 10 user inputs and fill the prices array with it
		for(int i = 0; i < 10; i++) {
			std::cout << "Enter price: ";
			std::cin >> userInput;
			if (userInput != -1) {
				prices[i] = userInput;
			} else {
				break;
			}
		}

		// Check the number of valid prices (prices greater than 0) and create a new array with only valid prices
		numOfValidPrices = 0;
		for(int i = 0; i < 10; i++) {
			if (prices[i] > 0) {
				validPrices[numOfValidPrices] = prices[i];
				numOfValidPrices++;
			}
		}

		// Calculate the minimum
		minValue = validPrices[0];
		for(int i = 0; i < numOfValidPrices; i++) {
			if(validPrices[i] < minValue) {
				minValue = validPrices[i];
			}
		}

		// Calculate the maximum
		maxValue = validPrices[0];
		for(int i = 0; i < numOfValidPrices; i++) {
			if(validPrices[i] > maxValue) {
				maxValue = validPrices[i];
			}
		}

		// Calculate the average
		average = 0;
		for(int i = 0; i < numOfValidPrices; i++) {
			average = average + validPrices[i];
		}
		average = average / numOfValidPrices;

		// Generate the output that the user sees
		std::cout << std::endl;
		std::cout << "Number of valid prices: " << numOfValidPrices << std::endl;
		std::cout << "Maximum: $" << maxValue << std::endl;
		std::cout << "Minimum: $" << minValue << std::endl;
		std::cout << "Range: $" << maxValue - minValue << std::endl;
		std::cout << "Average: $" << average << std::endl;
		std::cout << std::endl;
	}
	return 0;
}
