#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {

  std::string s;
  std::getline(std::cin, s);

  int n = std::stoi(s);
  s.clear();
  std::vector<std::string> vec;

  for (int i = 0; i < n; ++i) {
    std::getline(std::cin, s);
    vec.push_back(s);
  }

  for (auto &s : vec) {

    std::stringstream ss(s);
    std::vector<std::string> vec2;
    s.clear();

    while (ss >> s) {
      vec2.push_back(s);
    }

    int h = std::stoi(vec2[0]);
    int w = std::stoi(vec2[1]);
    int order = std::stoi(vec2[2]);

    int q = order / h; // 호수를 결정 0인 경우 1호 -> q+1호
    int r = order % h; // 층수를 결정 // 1인 경우 1호

    if (r == 0) {
      r = h;
      q -= 1;
    }
    if (q + 1 < 10) {
      std::cout << r << 0 << q + 1 << std::endl;
    } else {
      std::cout << r << q + 1 << std::endl;
    }
  }

  return 0;
}