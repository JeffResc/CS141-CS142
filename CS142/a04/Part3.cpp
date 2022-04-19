#include<iostream>
#include<string>

float calc(float f1, float f2, char op) {
  if (f1 && f2 && op) {
    switch(op) {
      case '+':
        return f1+f2;
        break;
      case '-':
        return f1-f2;
        break;
      case '*':
        return f1*f2;
        break;
      case '/':
        return f1/f2;
        break;
      default:
        return -999.999;
        break;
    }
  } else {
    return -999.999;
  }
}

int main() {
  bool keepGoing = true;
  while(keepGoing) {
    float float1;
    float float2;
    char op;
    std::cout << "Input an arithmetic expression: ";
    std::cin >> float1 >> op >> float2;
    float result = calc(float1, float2, op);
    if (result == -999.999) {
      std::cout << "Unable to calculate. Quitting..." << std::endl;
      keepGoing = false;
    } else {
      std::cout << float1 << ' ' << op << ' ' << float2 << " = " << result << std::endl;
    }
  }
  return 0;
}
