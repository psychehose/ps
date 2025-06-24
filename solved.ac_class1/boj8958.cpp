#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {

  int n;

  std::cin >> n;
  std::vector<int> vec;

  for (int i = 0; i < n; ++i) {

    std::string s;

    std::cin >> s;
    int score = 0;
    int cnt = 0;
    for (const auto &c : s) {
      if (c == 'O') {
        cnt++;
      } else {
        cnt = 0;
      }
      score += cnt;
    }
    vec.push_back(score);
  }

  for (auto el : vec) {
    std::cout << el << std::endl;
  }

  return 0;
}