#include <ios>
#include <iostream>
#include <string>

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n;

  std::cin >> n;

  int cur = 666;

  int res = 0;

  while (true) {
    std::string s = std::to_string(cur);
    if (s.find("666") != std::string::npos) {
      res++;

      if (n == res)
        break;
    }
    cur++;
  }

  std::cout << cur << std::endl;

  return 0;
}