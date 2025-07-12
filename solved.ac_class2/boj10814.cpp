#include <algorithm>
#include <ios>
#include <iostream>
#include <ostream>
#include <string>
#include <utility>
#include <vector>

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  int n;

  std::cin >> n;

  std::vector<std::pair<int, std::string>> vec(n, {0, ""});

  for (int i = 0; i < n; ++i) {
    std::cin >> vec[i].first >> vec[i].second;
  }

  std::stable_sort(
      vec.begin(), vec.end(),
      [](std::pair<int, std::string> p1, std::pair<int, std::string> p2) {
        return p1.first < p2.first;
      });

  for (const auto &el : vec) {
    std::cout << el.first << " " << el.second << "\n";
  }
  return 0;
}