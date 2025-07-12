#include <ios>
#include <iostream>
#include <utility>
#include <vector>

int main() {

  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;

  std::vector<std::pair<int, int>> vec(n, {0, 0});

  for (int i = 0; i < n; ++i) {
    std::cin >> vec[i].first >> vec[i].second;
  }

  std::vector<int> res(n);

  for (int i = 0; i < n; ++i) {

    int l = 0;

    for (int j = 0; j < n; ++j) {
      if (i == j)
        continue;
      if (vec[i].first < vec[j].first && vec[i].second < vec[j].second) {
        l++;
      }
    }
    res[i] = l + 1;
  }

  for (const auto &el : res) {
    std::cout << el << " ";
  }
  std::cout << "\n";
  return 0;
}