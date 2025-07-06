
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

bool is_word(const std::string &str) { return std::isdigit(str.at(0)); }
std::string get_result(int num) {
  if (num % 3 == 0 && num % 5 == 0) {
    return "FizzBuzz";
  } else if (num % 3 == 0) {
    return "Fizz";
  } else if (num % 5 == 0) {
    return "Buzz";
  } else {
    return std::to_string(num);
  }
}

int main() {
  std::vector<std::string> vec;
  int num_last_idx = 0;

  for (int i = 0; i < 3; ++i) {
    std::string s;
    std::cin >> s;
    vec.push_back(s);
    if (is_word(s)) {
      num_last_idx = i;
    }
  }

  int num_last = std::stoi(vec.at(num_last_idx));

  if (num_last_idx == 0) {
    std::cout << get_result(num_last + 3) << std::endl;
  } else if (num_last_idx == 1) {
    std::cout << get_result(num_last + 2) << std::endl;
  } else {
    std::cout << get_result(num_last + 1) << std::endl;
  }

  return 0;
}