#include <iostream>
#include <string>

int main() {

  std::vector<int> vec(9, 0);
  int maxvalue = 0;
  int maxidx = 0;

  for (int i = 0; i < 9; ++i) {
    std::string s;
    std::getline(std::cin, s);

    vec[i] = std::stoi(s);

    if (maxvalue < vec[i]) {
      maxvalue = vec[i];
      maxidx = i;
    }
  }

  std::cout << maxidx + 1 << std::endl;

  return 0;
}