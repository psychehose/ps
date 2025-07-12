#include <ios>
#include <iostream>

int main() {

  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;

  int res = 0;

  for (int i = 0; i <= n; i += 5) {

    int temp = i;

    while (temp / 5 != 0 && temp % 5 == 0) {
      temp /= 5;
      res++;
    }
  }

  std::cout << res << std::endl;

  return 0;
}