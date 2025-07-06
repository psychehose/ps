#include <iostream>

int main() {

  int num1, num2;
  std::cin >> num1 >> num2;

  int gcd = 1;

  for (int i = 1; i <= num1; ++i) {
    if (num1 % i == 0 && num2 % i == 0) {
      gcd = i;
    }
  }

  std::cout << gcd << std::endl;
  std::cout << (num1 / gcd) * (num2 / gcd) * gcd << std::endl;

  return 0;
}