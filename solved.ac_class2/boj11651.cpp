#include <algorithm>
#include <ios>
#include <iostream>
#include <utility>
#include <vector>
int main() {

  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> vec(n);

  for (int i = 0; i < n; ++i) {
    std::cin >> vec[i].first >> vec[i].second;
  }

  std::sort(vec.begin(), vec.end(),
            [](std::pair<int, int> p1, std::pair<int, int> p2) {
              if (p1.second == p2.second) {
                return p1.first < p2.first;
              }
              return p1.second < p2.second;
            });

  for (const auto &el : vec) {
    std::cout << el.first << " " << el.second << "\n";
  }

  return 0;
}