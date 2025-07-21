#include <ios>
#include <iostream>

const int MOD = 8101;

long long power_mod(long long base, long long exp) {
  long long result = 1;

  while (exp > 0) {
    if (exp & 1) {
      result = (base * result) % MOD;
    }
    base = base * base % MOD;
    exp >>= 1;
  }

  return result;
}

long long modInverse(long long a) { return power_mod(a, MOD - 2); }

long long comb_mode(long long n, long long k) {
  if (k > n || k < 0)
    return 0;
  if (k == 0 || k == n)
    return 1;

  long long numerator = 1;
  long long denominator = 1;

  for (long long i = 0; i < k; i++) {
    numerator = (numerator * (n - i)) % MOD;
    denominator = (denominator * (i + 1)) % MOD;
  }

  return (numerator * modInverse(denominator)) % MOD;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;

  long long result = (comb_mode(2 * n, n) * modInverse(n + 1)) % MOD;

  std::cout << result << "\n";

  return 0;
}