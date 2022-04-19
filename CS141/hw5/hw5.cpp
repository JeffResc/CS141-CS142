#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

struct person {
  std::string firstName;
  std::string middleName;
  std::string lastName;
};

struct myWage {
  float hourlyWage;
  bool overtimeEligibility;
  float overtimeRate;
};

struct timeCard {
  float hoursWorked;
  float lengthOfLunchBreak;
  float overtimeHoursWorked;
  float totalPay;
};

struct employee {
  person employeeName;
  person managerName;
  myWage wage;
  std::string department;
  timeCard fiveDayTimeCard[5];
};

bool readData(std::string);
bool writeData(std::string);
bool overtimeBoolSetter(char);
float hoursWorked(std::string, std::string, std::string, std::string);
float breakLength(std::string, std::string, std::string, std::string);
float overTimeHours(employee);
float totalDayPay(float, float, float, float, bool);
float timeToHours(std::string);

employee allEmployees[20];

int main() {
  std::string fileName;
  std::cout << "Welcome to the payroll program." << std::endl;
  std::cout << "Input the input filename: ";
  //fileName = "payrollData.txt";
  std::cin >> fileName;
  if (readData(fileName)) {
    std::cout << "Input the output filename: ";
    std::cin >> fileName;
    if(writeData(fileName) == 1) {
      std::cout << "Successfully written to file: " << fileName << std::endl;
    } else {
      std::cout << "Unable to open ouput file. This is because the file extension is not xml, the file already exists, or you do not have the correct user permission." << std::endl;
    }
  } else {
    std::cout << "Unable to open input file." << std::endl;
  }
}

bool readData(std::string fileName) {
  int employeeDay[20];
  std::ifstream inputFileStream;
  inputFileStream.open(fileName.c_str());
  if (!inputFileStream.fail()) {
    int employeeNum = 0;
    char wageIdentifier;
    std::string dayClockIn;
    std::string lunchClockOut;
    std::string postLunchClockIn;
    std::string dayClockOut;
    for(employeeDay[employeeNum]=0; employeeDay[employeeNum]<5; employeeDay[employeeNum]++) {
      inputFileStream >> allEmployees[employeeNum].wage.hourlyWage >> wageIdentifier >> allEmployees[employeeNum].wage.overtimeRate >> allEmployees[employeeNum].employeeName.firstName >> allEmployees[employeeNum].employeeName.middleName >> allEmployees[employeeNum].employeeName.lastName >> allEmployees[employeeNum].department >> allEmployees[employeeNum].managerName.firstName >> allEmployees[employeeNum].managerName.middleName >> allEmployees[employeeNum].managerName.lastName >> dayClockIn >> lunchClockOut >> postLunchClockIn >> dayClockOut;
      allEmployees[employeeNum].wage.overtimeEligibility = overtimeBoolSetter(wageIdentifier);
      allEmployees[employeeNum].fiveDayTimeCard[employeeDay[employeeNum]].hoursWorked = hoursWorked(dayClockIn, lunchClockOut, postLunchClockIn, dayClockOut);
      allEmployees[employeeNum].fiveDayTimeCard[employeeDay[employeeNum]].lengthOfLunchBreak = breakLength(dayClockIn, lunchClockOut, postLunchClockIn, dayClockOut);
      allEmployees[employeeNum].fiveDayTimeCard[employeeDay[employeeNum]].totalPay = totalDayPay(allEmployees[employeeNum].fiveDayTimeCard[employeeDay[employeeNum]].hoursWorked, allEmployees[employeeNum].fiveDayTimeCard[employeeDay[employeeNum]].overtimeHoursWorked, allEmployees[employeeNum].wage.hourlyWage, allEmployees[employeeNum].wage.overtimeRate, allEmployees[employeeNum].wage.overtimeEligibility);
      if(employeeDay[employeeNum] == 4) {
        for(int j=0; j<5; j++) {
          allEmployees[employeeNum].fiveDayTimeCard[j].overtimeHoursWorked = overTimeHours(allEmployees[employeeNum]);
          allEmployees[employeeNum].fiveDayTimeCard[j].totalPay = totalDayPay(allEmployees[employeeNum].fiveDayTimeCard[employeeDay[employeeNum]].hoursWorked, allEmployees[employeeNum].fiveDayTimeCard[j].overtimeHoursWorked, allEmployees[employeeNum].wage.hourlyWage, allEmployees[employeeNum].wage.overtimeRate, allEmployees[employeeNum].wage.overtimeEligibility);
        }
      }
    }
    for(employeeNum=1; employeeNum<20; employeeNum++) {
      for(employeeDay[employeeNum]=0; employeeDay[employeeNum]<5; employeeDay[employeeNum]++) {
        inputFileStream >> allEmployees[employeeNum].wage.hourlyWage >> wageIdentifier >> allEmployees[employeeNum].wage.overtimeRate >> allEmployees[employeeNum].employeeName.firstName >> allEmployees[employeeNum].employeeName.middleName >> allEmployees[employeeNum].employeeName.lastName >> allEmployees[employeeNum].department >> allEmployees[employeeNum].managerName.firstName >> allEmployees[employeeNum].managerName.middleName >> allEmployees[employeeNum].managerName.lastName >> dayClockIn >> lunchClockOut >> postLunchClockIn >> dayClockOut;
        allEmployees[employeeNum].wage.overtimeEligibility = overtimeBoolSetter(wageIdentifier);
        allEmployees[employeeNum].fiveDayTimeCard[employeeDay[employeeNum]].hoursWorked = hoursWorked(dayClockIn, lunchClockOut, postLunchClockIn, dayClockOut);
        allEmployees[employeeNum].fiveDayTimeCard[employeeDay[employeeNum]].lengthOfLunchBreak = breakLength(dayClockIn, lunchClockOut, postLunchClockIn, dayClockOut);
        if(employeeDay[employeeNum] == 4) {
          for(int j=0; j<5; j++) {
            allEmployees[employeeNum].fiveDayTimeCard[j].overtimeHoursWorked = overTimeHours(allEmployees[employeeNum]);
            allEmployees[employeeNum].fiveDayTimeCard[j].totalPay = totalDayPay(allEmployees[employeeNum].fiveDayTimeCard[employeeDay[employeeNum]].hoursWorked, allEmployees[employeeNum].fiveDayTimeCard[j].overtimeHoursWorked, allEmployees[employeeNum].wage.hourlyWage, allEmployees[employeeNum].wage.overtimeRate, allEmployees[employeeNum].wage.overtimeEligibility);
          }
        }
      }
    }
    inputFileStream.close();
    return true;
  } else {
    return false;
  }
  return false;
};

bool overtimeBoolSetter(char wageIdentifier) {
  if (wageIdentifier == 'Y') {
    return true;
  } else {
    return false;
  }
}

bool writeData(std::string fileName) {
  if(fileName.substr(fileName.find('.')+1, fileName.length()) == "xml") {
    std::ofstream outputFileStream;
    outputFileStream.open(fileName.c_str());
    outputFileStream << "<payroll>" << "\n";
    for(int i=0;i<20;i++) {
      outputFileStream << "  " << "<employee>" << "\n";
      if (allEmployees[i].employeeName.middleName == "NONE") {
        outputFileStream << "    " << "<name>" << allEmployees[i].employeeName.firstName << ' ' << allEmployees[i].employeeName.lastName << "</name>" << "\n";
      } else {
        outputFileStream << "    " << "<name>" << allEmployees[i].employeeName.firstName << ' ' << allEmployees[i].employeeName.middleName << ' ' << allEmployees[i].employeeName.lastName << "</name>" << "\n";
      }
      outputFileStream << "    " << "<department>" << allEmployees[i].department << "</department>" << "\n";
      outputFileStream << "    " << "<payrate>" << allEmployees[i].wage.hourlyWage << "</payrate>" << "\n";
      outputFileStream << "    " << "<hours>" << allEmployees[i].fiveDayTimeCard[0].hoursWorked+allEmployees[i].fiveDayTimeCard[1].hoursWorked+allEmployees[i].fiveDayTimeCard[2].hoursWorked+allEmployees[i].fiveDayTimeCard[3].hoursWorked+allEmployees[i].fiveDayTimeCard[4].hoursWorked << "</hours>" << "\n";
      outputFileStream << "    " << "<overhours>" << allEmployees[i].fiveDayTimeCard[0].overtimeHoursWorked+allEmployees[i].fiveDayTimeCard[1].overtimeHoursWorked+allEmployees[i].fiveDayTimeCard[2].overtimeHoursWorked+allEmployees[i].fiveDayTimeCard[3].overtimeHoursWorked+allEmployees[i].fiveDayTimeCard[4].overtimeHoursWorked << "</overhours>" << "\n";
      outputFileStream << "    " << "<pay>" << allEmployees[i].fiveDayTimeCard[0].totalPay+allEmployees[i].fiveDayTimeCard[1].totalPay+allEmployees[i].fiveDayTimeCard[2].totalPay+allEmployees[i].fiveDayTimeCard[3].totalPay+allEmployees[i].fiveDayTimeCard[4].totalPay << "</pay>" << "\n";
      outputFileStream << "  " << "</employee>" << "\n";
    }
    outputFileStream << "</payroll>";
    outputFileStream.close();
    return true;
  } else {
    return false;
  }
  return false;
}

float hoursWorked(std::string dayClockIn, std::string lunchClockOut, std::string postLunchClockIn, std::string dayClockOut) {
  return (timeToHours(dayClockOut) - timeToHours(dayClockIn)) - breakLength(dayClockIn, lunchClockOut, postLunchClockIn, dayClockOut);
}

float breakLength(std::string dayClockIn, std::string lunchClockOut, std::string postLunchClockIn, std::string dayClockOut) {
  return timeToHours(postLunchClockIn) - timeToHours(lunchClockOut);
}

float overTimeHours(employee thisEmployee) {
  float totalHoursWorked = thisEmployee.fiveDayTimeCard[0].hoursWorked + thisEmployee.fiveDayTimeCard[1].hoursWorked + thisEmployee.fiveDayTimeCard[2].hoursWorked + thisEmployee.fiveDayTimeCard[3].hoursWorked + thisEmployee.fiveDayTimeCard[4].hoursWorked;
  if (totalHoursWorked > 37.5) {
    return (totalHoursWorked - 37.5)/5;
  } else {
    return 0;
  }
}

float totalDayPay(float totalHoursWorked, float overtimeHoursWorked, float wage, float overtimeRate, bool overtimeEligibility) {
  float totalPay = 0;
  if (overtimeEligibility) {
    if (overtimeRate == 0) {
      overtimeRate = 1;
    }
    totalPay = overtimeHoursWorked * wage * overtimeRate;
    totalHoursWorked = totalHoursWorked - overtimeHoursWorked;
  }
  totalPay = totalPay + (totalHoursWorked * wage);
  return totalPay;
}

float timeToHours(std::string timeInString) {
  int locOfDivider = timeInString.find(':');
  int timeHoursInt;
  int timeMinsInt;
  std::string timeHours = timeInString.substr(0, locOfDivider);
  std::string timeMins = timeInString.substr(locOfDivider+1, timeInString.length());

  std::istringstream(timeHours) >> timeHoursInt;
  std::istringstream(timeMins) >> timeMinsInt;
  return timeHoursInt + (timeMinsInt/60);
}
