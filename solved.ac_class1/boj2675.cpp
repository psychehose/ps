#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {

  int n;
  std::cin >> n;
  std::cin.ignore();
  std::string str;
  std::vector<std::string> vec;

  for (int i = 0; i < n; ++i) {
    std::getline(std::cin, str);
    vec.push_back(str);
  }

  for (auto it = vec.begin(); it != vec.end(); ++it) {
    std::stringstream ss(*it);

    std::string num, word;
    ss >> num >> word;

    std::string answer;
    for (auto c : word) {
      std::string repeat(std::stoi(num), c);

      answer += repeat;
    }

    *it = answer;
  }

  for (auto s : vec) {
    std::cout << s << std::endl;
  }

  return 0;
}