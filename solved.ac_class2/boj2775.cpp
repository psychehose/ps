#include <iostream>
#include <vector>

int main() {

  int case_n;

  std::cin >> case_n;

  for (int i = 0; i < case_n; ++i) {
    int f, h;
    std::cin >> f >> h;

    std::vector<std::vector<int>> dp(15, std::vector<int>(15, 1));

    int cur = 1;
    while (cur <= h)
      dp[0][cur] = ++cur;

    for (int j = 1; j <= f; ++j) {
      for (int k = 2; k <= h; ++k) {
        dp[j][k] = dp[j][k - 1] + dp[j - 1][k];
      }
    }
    std::cout << dp[f][h] << std::endl;
  }

  return 0;
}