#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

int main() {

  int a, b, c;
  std::cin >> a >> b >> c;

  std::string s = std::to_string(a * b * c);

  std::vector<int> vec(10, 0);

  for (auto c : s) {
    vec[atoi(&c)]++;
  }

  for (auto &n : vec) {
    std::cout << n << std::endl;
  }

  return 0;
}