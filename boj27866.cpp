
#include <iostream>

int main() {

  std::string str;
  std::getline(std::cin, str);

  std::string num;
  std::getline(std::cin, num);

  int n = std::stoi(num);

  std::cout << str[n - 1] << std::endl;

  return 0;
}