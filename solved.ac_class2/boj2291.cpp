#include <iostream>

int main(int argc, const char *argv[]) {

  int n = 1;
  int k = 0;

  int input;
  std::cin >> input;

  while (true) {
    if (6 * k + n >= input) {
      break;
    }
    n = n + (6 * k);
    k++;
  }

  std::cout << k + 1 << std::endl;
  return 0;
}