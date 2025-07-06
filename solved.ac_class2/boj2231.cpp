#include <iostream>
#include <numeric>
#include <string>
#include <vector>

std::vector<int> getNums(std::string s) {

  std::vector<int> vec;

  for (int i = s.size() - 1; i >= 0; --i) {
    int q = s[i] - '0';
    vec.push_back(q);
  }

  return vec;
}

int main(int argc, const char *argv[]) {

  int n;
  std::cin >> n;
  int res = 0;

  for (int i = 0; i <= n; ++i) {

    std::vector<int> vec = getNums(std::to_string(i));
    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    if (i + sum == n) {
      res = i;
      break;
    }
  }

  std::cout << res << std::endl;

  return 0;
}