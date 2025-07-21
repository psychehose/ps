#include <ios>
#include <iostream>
#include <vector>

const int MOD = 8101;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;

  if (n <= 1) {
    return 0;
  }
  std::vector<int> dp(n + 1);
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 5;

  for (int i = 4; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      // O(n^2)
      dp[i] = (dp[i] % MOD + (dp[i - j] * dp[j]) % MOD) % MOD;
    }
  }

  std::cout << dp[n] << '\n';

  return 0;
}