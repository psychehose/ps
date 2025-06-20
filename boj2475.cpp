#include <iostream>
#include <string>

int main() {

  std::string str;
  std::getline(std::cin, str);

  int n = 0;
  for (auto &c : str) {
    if (c == ' ') {
      continue;
    } else {
      int digit = c - '0';
      n += digit * digit;
    }
  }

  std::cout << n << std::endl;

  return 0;
}