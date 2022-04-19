#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<cstdlib>

std::string employees[50][50];
std::string passwords[50];

void readEmployees() {
    std::ifstream file("employees.txt");
    std::string str;
    int i=0;
    if(file.is_open()) {
        while (std::getline(file, str)) {
            if(!str.empty()) {
                employees[i][0] = str;
                i++;
            }
        }
    }
}

void readPasswords() {
    std::ifstream file("passwords.txt");
    std::string str;
    int i=0;
    if(file.is_open()) {
        while (std::getline(file, str)) {
            if(!str.empty()) {
                passwords[i] = str;
                i++;
            }
        }
    }
}

void writeEmpPasswords() {
    std::ofstream file("empPasswords.txt");
    std::string str;
    int i=0;
    if(file.is_open()) {
        for(i=0; i<50; i++) {
            file << employees[i][0] << ' ' << employees[i][1] << std::endl;
        }
        file.close();
    }
}

void shuffle_password() {
    int randMax = 50;
    int t;
    int a[50];
    int randMin = 1;
    int randNum;
    srand (time (0));
    for(int i=0; i<50;) {
        randNum = rand () % 50;
        t=0;
        for(int y=i; y>=0; y--) {
            if(randNum == a[y]) {
                t=1;
                break;
            }
        }
        if(t==0) {
            if(i==0) {
                if(!(randNum==1||randNum==50)) {
                    a[i]=randNum;
                    i++;
                }
            } else {
                a[i]=randNum;
                i++;
            }
        }
    }
    for(int i=0; i<50; i++) {
        employees[i][1] = passwords[a[i]];
    }
}

int main() {
    readEmployees();
    readPasswords();
    shuffle_password();
    writeEmpPasswords();
    std::cout << "Done!" << std::endl;
}
