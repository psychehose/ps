#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int MOD = 1234567891;

long long power(long long base, long long exp) {
  long long result = 1;
  base %= MOD;

  while (exp > 0) {
    if (exp & 1)
      result = (result * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }
  return result;
}

int main(int argc, const char *argv[]) {

  int n;
  std::string s;
  std::cin >> n >> s;
  std::vector<int> vec;

  for (const auto &c : s) {
    vec.push_back(c - 'a' + 1);
  }

  long long res = 0;

  for (int i = 0; i < vec.size(); ++i) {
    long long num = vec[i] % MOD;
    long long ld = power(31, i) % MOD;
    res += (num * ld) % MOD;
    res %= MOD;
  }

  std::cout << res << std::endl;
  return 0;
}