#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {

  std::vector<int> vec(26, -1);

  std::string s;

  std::cin >> s;

  for (int i = 0; i < s.length(); ++i) {
    if (vec[s[i] - 'a'] == -1) {
      vec[s[i] - 'a'] = i;
    }
  }

  for (const auto num : vec) {
    std::cout << num << " ";
  }

  return 0;
}