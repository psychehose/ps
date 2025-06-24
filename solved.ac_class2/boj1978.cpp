#include <iostream>
#include <vector>

bool isPrime(int n) {

  if (n <= 1)
    return false;
  if (n == 2)
    return true;
  if (n % 2 == 0)
    return false;

  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0)
      return false;
  }
  return true;
}

int main(int argc, char *agrv[]) {

  int n;
  std::cin >> n;

  std::vector<int> vec;

  for (int i = 0; i < n; ++i) {
    int num;
    std::cin >> num;
    vec.push_back(num);
  }
  int res = 0;

  for (auto el : vec) {
    if (isPrime(el))
      res++;
  }

  std::cout << res << std::endl;

  return 0;
}