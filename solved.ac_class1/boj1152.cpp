#include <iostream>
#include <sstream>
#include <string>

int main() {

  std::string line;

  std::getline(std::cin, line);

  std::stringstream ss(line);
  std::string word;
  int n = 0;
  while (ss >> word) {
    n++;
  }

  std::cout << n << std::endl;

  return 0;
}