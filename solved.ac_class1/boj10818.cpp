#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

int main() {

  std::string str;
  std::getline(std::cin, str);

  int n = std::stoi(str);
  str.clear();

  std::getline(std::cin, str);

  std::stringstream ss(str);
  str.clear();

  std::vector<int> vec;

  while (ss >> str) {
    vec.push_back(std::stoi(str));
  }
  std::sort(vec.begin(), vec.end());

  std::cout << vec[0] << " " << vec[n - 1] << std::endl;
  return 0;
}