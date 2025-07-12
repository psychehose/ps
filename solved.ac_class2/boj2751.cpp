#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;

  std::vector<int> vec(n, 0);

  for (int i = 0; i < n; ++i) {
    std::cin >> vec[i];
  }

  std::sort(vec.begin(), vec.end());

  for (const auto &el : vec) {
    std::cout << el << std::endl;
  }

  return 0;
}