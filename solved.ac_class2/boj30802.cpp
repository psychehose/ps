#include <iostream>
#include <sstream>
#include <string>

int main(int argc, const char *argv[]) {

  int n;
  int s, m, l, xl, xxl, xxxl;
  int t, p;
  std::cin >> n >> s >> m >> l >> xl >> xxl >> xxxl >> t >> p;

  std::vector<int> sizes;
  sizes.push_back(s);
  sizes.push_back(m);
  sizes.push_back(l);
  sizes.push_back(xl);
  sizes.push_back(xxl);
  sizes.push_back(xxxl);

  int res_cloth = 0;
  int res_pen_pack = (n / p);
  int res_pen_one = (n % p);

  for (auto size : sizes) {
    int q = size / t;
    int r = size % t;

    res_cloth += q;
    if (r != 0) {
      res_cloth += 1;
    }
  }

  std::cout << res_cloth << std::endl;
  std::cout << res_pen_pack << " " << res_pen_one << std::endl;

  return 0;
}