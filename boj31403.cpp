#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> strs;

  int n = 3;

  for (int i = 0; i < n; ++i) {
    std::string str;
    getline(std::cin, str);
    strs.push_back(str);
  }

  int r1 = std::stoi(strs[0]) + std::stoi(strs[1]) - std::stoi(strs[2]);
  int r2 = std::stoi(strs[0] + strs[1]) - std::stoi(strs[2]);

  std::cout << r1 << std::endl;
  std::cout << r2 << std::endl;

  return 0;
}