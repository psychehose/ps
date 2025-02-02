#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int res = *std::max_element(nums.begin(), nums.end());

    int curMin = 1;
    int curMax = 1;

    for (auto n : nums) {

      if (n == 0) {
        curMin = 1;
        curMax = 1;
        continue;
      }

      int tempMax = curMax * n;
      int tempMin = curMin * n;

      curMax = max(tempMin, tempMax);
      curMax = max(curMax, n);
      curMin = min(tempMin, tempMax);
      curMin = min(curMin, n);

      res = max(curMax, res);
    }

    return res;
  }
};