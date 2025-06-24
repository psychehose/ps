#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {

  std::vector<std::string> vec_str;
  while (true) {
    int l1, l2, l3;
    std::cin >> l1 >> l2 >> l3;
    if (l1 == 0 && l2 == 0 && l3 == 0) {
      break;
    }

    std::vector<int> vec;
    vec.push_back(l1);
    vec.push_back(l2);
    vec.push_back(l3);

    sort(vec.begin(), vec.end());

    if (pow(vec[2], 2) == pow(vec[0], 2) + pow(vec[1], 2)) {
      vec_str.push_back("right");
    } else {
      vec_str.push_back("wrong");
    }
  }

  for (const auto &s : vec_str) {
    std::cout << s << std::endl;
  }

  return 0;
}