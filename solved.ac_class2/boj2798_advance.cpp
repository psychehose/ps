#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, const char *argv[]) {

  int n, m;
  std::cin >> n >> m;

  std::vector<int> cards(n);

  for (int i = 0; i < n; ++i) {
    std::cin >> cards[i];
  }

  std::sort(cards.begin(), cards.end());

  int res = 0;
  for (int i = 0; i < n - 2; ++i) {

    int l = i + 1;
    int r = n - 1;

    while (l < r) {
      int sum = cards[i] + cards[l] + cards[r];

      if (sum == m) {
        std::cout << sum << std::endl;
        return 0;
      } else if (sum < m) {
        res = std::max(res, sum);
        l++;
      } else {
        r--;
      }
    }
  }

  std::cout << res << std::endl;
  return 0;
}