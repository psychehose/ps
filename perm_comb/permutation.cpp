#include <algorithm>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>

std::vector<std::vector<int>> permutation(std::vector<int> seed, int k) {

  std::vector<std::vector<int>> vec;
  std::sort(seed.begin(), seed.end());

  std::vector<bool> selector(seed.size(), false);

  for (int i = 0; i < k; ++i) {
    selector[i] = true;
  }

  do {
    std::vector<int> v;
    for (int i = 0; i < seed.size(); ++i) {
      if (selector[i])
        v.push_back(seed[i]);
    }
    vec.push_back(v);
  } while (std::next_permutation(seed.begin(), seed.end()));

  return std::move(vec);
}

std::vector<std::vector<int>> permutation_b(std::vector<int> seed, int k) {

  std::vector<bool> used(seed.size(), false);

  std::vector<std::vector<int>> vec;
  std::vector<int> temp(k);

  std::function<void(int)> back = [&](int p) {
    if (p == k) {
      vec.push_back(temp);
      return;
    }

    for (int i = 0; i < seed.size(); ++i) {
      if (!used[i]) {
        used[i] = true;
        temp[p] = seed[i];
        back(p + 1);
        used[i] = false;
      }
    }
  };

  back(0);

  return vec;
}

int main() {
  std::vector<int> seed = {3, 2, 1, 4};
  // std::vector<std::vector<int>> perm = permutation(seed, 2);
  std::vector<std::vector<int>> perm = permutation_b(seed, 3);

  for (auto &e : perm) {
    for (auto &e2 : e) {
      std::cout << e2 << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
