#include<iostream>
#include<string>
#include<fstream>

struct Location {
  std::string building;
  int floorLevel;
};

struct Drink {
  std::string name;
  float bottleSize;
  float price;
};

struct VendingMachine {
  Location location;
  Drink drink[10];
};

VendingMachine AllVendingMachines[5];

int main() {
  std::ifstream inputFileStream;
  inputFileStream.open("vendingmachinedata.txt");
  int drinkNumber = 0;
  int machineNumber = 0;
  VendingMachine currentMachine;
  int machineFloorLevel;
  while(!inputFileStream.eof()) {
    if (drinkNumber > 10) {
      drinkNumber = 0;
      machineNumber++;
    }
    inputFileStream >> currentMachine.location.building >> currentMachine.location.floorLevel >> AllVendingMachines[machineNumber].drink[drinkNumber].name >> AllVendingMachines[machineNumber].drink[drinkNumber].bottleSize >> AllVendingMachines[machineNumber].drink[drinkNumber].price;
    if (drinkNumber == 0) {
      AllVendingMachines[machineNumber].location.building = currentMachine.location.building;
      AllVendingMachines[machineNumber].location.floorLevel = currentMachine.location.floorLevel;
    }
    drinkNumber++;
  }
  inputFileStream.close();
  std::cout << "Welcome to the vending machine inventory software." << std::endl;
  std::string userInput;
  while(userInput != "EXIT") {
    std::cout << "Please input a command: ";
    std::cin >> userInput;
    if (userInput == "BUY") {
      VendingMachine currentMachine;
      std::cout << "Enter a building name: ";
      std::cin >> currentMachine.location.building;
      std::cout << "Enter a floor level: ";
      std::cin >> currentMachine.location.floorLevel;
      std::cout << "Enter a drink name: ";
      std::cin >> currentMachine.drink[0].name;
      std::cout << "Enter a drink size: ";
      std::cin >> currentMachine.drink[0].bottleSize;
      bool found = false;
      for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 10; j++) {
          if (!found) {
            if (currentMachine.location.building == AllVendingMachines[i].location.building && currentMachine.location.floorLevel == AllVendingMachines[i].location.floorLevel && currentMachine.drink[0].name == AllVendingMachines[i].drink[j].name && currentMachine.drink[0].bottleSize == AllVendingMachines[i].drink[j].bottleSize) {
              std::cout << "Product found at price $" << AllVendingMachines[i].drink[j].price << std::endl << "Purchase successful" << std::endl;
              AllVendingMachines[i].drink[j].name = "null";
              AllVendingMachines[i].drink[j].bottleSize = 0;
              AllVendingMachines[i].drink[j].price = 0;
              found = true;
            }
          }
        }
      }
      if (!found) {
        std::cout << "Product not found... Please try again." << std::endl;
      }
    } else if (userInput == "SHOW") {
      std::cout << "Inventory Report: " << std::endl;
      std::cout << "----------" << std::endl;
      int drinkTotal = 0;
        for(int i = 0; i < 5; i++) {
          std::cout << "Building: " << AllVendingMachines[i].location.building << " | Floor: " << AllVendingMachines[i].location.floorLevel << std::endl;
          std::cout << "----------" << std::endl;
          int machineDrinkTotal = 0;
          for(int j = 0; j < 10; j++) {
            if (AllVendingMachines[i].drink[j].name != "null" && AllVendingMachines[i].drink[j].price != 0) {
              std::cout << "Name: " << AllVendingMachines[i].drink[j].name << " | Size: " << AllVendingMachines[i].drink[j].bottleSize << " | Price: $" << AllVendingMachines[i].drink[j].price << std::endl;
              drinkTotal++;
              machineDrinkTotal++;
            }
          }
          std::cout << "Machine Drink Total: " << machineDrinkTotal << std::endl;
          std::cout << "----------" << std::endl;
        }
        std::cout << "Total Drinks in All Machines: " << drinkTotal << std::endl;
    } else if (userInput == "EXIT") {
      return 0;
    } else {
      std::cout << "Command not recognized." << std::endl;
    }
  }
  return 0;
}
