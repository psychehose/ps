#include <iostream>

int main() {

  int a, b, v;
  std::cin >> a >> b >> v;

  if (a == v) {
    std::cout << "1" << std::endl;
    return 0;
  }

  int prev = v - a;
  int cycle = a - b;

  if (cycle >= prev) {
    std::cout << "2" << std::endl;
    return 0;
  } else {
    int step = prev / cycle;
    int more = prev % cycle;

    if (more == 0) {
      std::cout << step + 1 << std::endl;
    } else {
      std::cout << step + 2 << std::endl;
    }
  }

  return 0;
}