#include <ios>
#include <iostream>

int factorial(int n) {
  int num = 1;

  while (n > 1) {
    num *= n;
    n--;
  }
  return num;
}

int main() {
  std::cin.tie(NULL);
  std::ios_base::sync_with_stdio(false);

  int n, k;
  std::cin >> n >> k;

  int res = 1;
  if (n == k || k == 0) {
    std::cout << res << "\n";
  } else {
    res = factorial(n) / (factorial(n - k) * factorial(k));
    std::cout << res << "\n";
  }

  return 0;
}