#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, const char *argv[]) {

  int num, target;

  std::cin >> num >> target;
  std::cin.ignore();

  std::vector<int> vec;
  std::string s;
  std::getline(std::cin, s);
  std::stringstream ss(s);
  std::string n;

  while (ss >> n) {
    vec.push_back(std::stoi(n));
  }

  int res = 0;
  std::sort(vec.begin(), vec.end());

  for (int i = 0; i < vec.size() - 2; ++i) {
    for (int j = i + 1; j < vec.size() - 1; ++j) {
      for (int k = j + 1; k < vec.size(); ++k) {
        if (vec[i] + vec[j] + vec[k] <= target) {
          res = std::max(res, vec[i] + vec[j] + vec[k]);
        }
      }
    }
  }

  std::cout << res << std::endl;
  return 0;
}