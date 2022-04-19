#include<iostream>
#include<string>
#include<fstream>

int iterationNumber;
std::string username;
std::string firstName;
std::string lastName;
std::string employeeFirstName;
std::string employeeLastName;
std::string employeeName;
std::ifstream employeeNamesTXT;
std::ofstream employeeDataTXT;

std::string generateEmailAddress(std::string, std::string);

int main() {
  employeeNamesTXT.open("employeeNames.txt");
  employeeDataTXT.open("employeesData.txt");
  employeeNamesTXT >> employeeName;
  while(!employeeNamesTXT.eof()) {
    employeeNamesTXT >> employeeFirstName >> employeeLastName;
    employeeDataTXT << employeeFirstName << " " << employeeLastName << " " << generateEmailAddress(employeeFirstName, employeeLastName) << std::endl;
  }
  std::cout << "Results written to file!" << std::endl;
  employeeDataTXT.close();
  employeeNamesTXT.close();
  return 0;
}

// Function: generateEmailAddress
// Input: std::string (firstName), std::string (lastName)
// Output: std::string (Generated Email Address)
std::string generateEmailAddress(std::string firstName, std::string lastName) {
  username = tolower(firstName[0]);
  if (lastName.length() > 7) {
    iterationNumber = 7;
  } else {
    iterationNumber = lastName.length();
  }
  for(int i = 0; i < iterationNumber; i++) {
    username += tolower(lastName[i]);
  }
  username += "@company.com";
  return username;
}
