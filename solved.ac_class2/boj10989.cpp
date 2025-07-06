#include <ios>
#include <iostream>
#include <vector>

int main() {

  std::cin.tie(NULL);
  std::ios_base::sync_with_stdio(false);

  int n;

  std::cin >> n;
  std::vector<int> vec(10001, 0);

  for (int i = 0; i < n; ++i) {
    int num;
    std::cin >> num;
    vec[num]++;
  }

  for (int i = 1; i <= 10000; ++i) {
    if (vec[i] == 0)
      continue;

    for (int j = 0; j < vec[i]; ++j) {
      std::cout << i << "\n";
    }
  }

  return 0;
}