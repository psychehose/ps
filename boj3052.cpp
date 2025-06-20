#include <iostream>
#include <unordered_set>

int main() {
  std::unordered_set<int> set;
  for (int i = 0; i < 10; ++i) {
    int n;
    std::cin >> n;
    int r = n % 42;
    set.insert(r);
  }

  std::cout << set.size() << std::endl;

  return 0;
}