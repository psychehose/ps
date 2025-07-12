#include <algorithm>
#include <ios>
#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {

  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;

  std::set<std::string> set;

  for (int i = 0; i < n; ++i) {
    std::string s;
    std::cin >> s;
    set.insert(s);
  }

  std::vector<std::string> v(set.begin(), set.end());

  sort(v.begin(), v.end(), [](std::string s1, std::string s2) {
    if (s1.size() == s2.size()) {
      return s1 < s2;
    } else {
      return s1.size() < s2.size();
    }
  });
  for (auto s : v) {
    std::cout << s << std::endl;
  }

  return 0;
}