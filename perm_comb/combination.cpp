#include <algorithm>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>

std::vector<std::vector<int>> combination_stl(std::vector<int> seed, int k) {

  std::vector<std::vector<int>> vec;
  std::sort(seed.begin(), seed.end());

  std::vector<int> temp(k);

  std::function<void(int, int)> back = [&](int p, int start) {
    if (p == k) {
      vec.push_back(temp);
      return;
    }

    for (int i = start; i < seed.size(); ++i) {
      temp[p] = seed[i];
      back(p + 1, i + 1);
    }
  };

  back(0, 0);

  return std::move(vec);
}

int main() {

  std::vector<int> seed = {1, 2, 3, 4};
  int k = 2;

  std::vector<std::vector<int>> comb = combination_stl(seed, k);

  for (auto &e : comb) {
    for (auto &e2 : e) {
      std::cout << e2 << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}