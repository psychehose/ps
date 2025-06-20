#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {

  std::string line;
  std::getline(std::cin, line);

  std::stringstream ss(line);
  std::vector<std::string> vec;
  std::string s;
  while (ss >> s) {
    vec.push_back(s);
  }

  int h = std::stoi(vec[0]);
  int m = std::stoi(vec[1]);

  if (m < 45) {
    m = m + 15;
    h = h - 1;
  } else {
    m = m - 45;
  }

  if (h < 0) {
    h = 23;
  }

  std::cout << h << " " << m << std::endl;

  return 0;
}
