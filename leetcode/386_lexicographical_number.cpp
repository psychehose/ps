#include <vector>

using namespace std;

class Solution {
public:
  vector<int> lexicalOrder(int n) {
    vector<int> res(n, 0);
    int p = 1;
    // p를 이용해 i번째에 들어갈 값을 찾는 것. (trie 이용)

    for (int i = 0; i < n; ++i) {
      res[i] = p;
      // 더 이상 자식이 없는 경우
      if (p * 10 > n) {
        if (p == n)
          p /= 10;
        p += 1;
        while (p % 10 == 0)
          p /= 10;
      } else {
        // p를 자식으로 보낸다.
        p *= 10;
      }
    }
    return res;
  }
};