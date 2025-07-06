#include <iostream>
#include <string>

bool is_palindrome(const int &n) {

  std::string s = std::to_string(n);

  int mid = s.length() / 2;

  for (int i = 0; i < mid; ++i) {
    if (s[i] != s[s.length() - 1 - i]) {
      return false;
    }
  }

  return true;
}

int main(int argc, const char *argv[]) {

  int n;
  while (true) {
    std::cin >> n;
    if (n == 0) {
      return 0;
    }
    if (is_palindrome(n)) {
      std::cout << "yes" << std::endl;
    } else {
      std::cout << "no" << std::endl;
    }
  }
  return 0;
}