#include <cstdlib>
#include <ios>
#include <iostream>
#include <string>

int main() {
  std::cin.tie(NULL);
  std::ios_base::sync_with_stdio(false);

  std::string s;
  std::cin >> s;

  int target_idx = 0;
  int isbn_checksum = 0;

  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '*') {
      target_idx = i;
      continue;
    } else {
      int num = s[i] - '0';
      if (i % 2 == 0) {
        isbn_checksum += num;
      } else {
        isbn_checksum += num * 3;
      }
    }
  }

  int needed = 10 - (isbn_checksum % 10);

  if (needed == 10) {
    std::cout << "0" << std::endl;
    return 0;
  }

  if (target_idx % 2 == 0) {
    std::cout << needed << std::endl;
    return 0;
  }

  for (int i = 1; i < 10; ++i) {
    if (needed == (i * 3) % 10) {
      std::cout << i << std::endl;
      return 0;
    }
  }

  return 0;
}