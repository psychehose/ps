#include <algorithm>
#include <iostream>
#include <string>
int main() {

  std::string str;
  std::getline(std::cin, str);

  str.erase(std::remove(str.begin(), str.end(), ' '), str.end());

  if (str == "12345678") {
    std::cout << "ascending" << std::endl;

  } else if (str == "87654321") {
    std::cout << "descending" << std::endl;
  } else {
    std::cout << "mixed" << std::endl;
  }
  return 0;
}