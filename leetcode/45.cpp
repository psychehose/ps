#include <vector>

using namespace std;
class Solution {
public:
  int jump(vector<int> &nums) {

    if (nums.size() == 1)
      return 0;

    int curr = 0;
    int len = nums.size();
    int res = 0;

    while (curr < len) {

      int can_j = nums[curr];

      int max = 0;
      int next = 0;

      for (int i = 1; i <= can_j; ++i) {
        if (curr + i >= len - 1)
          return res + 1;
        if (i + nums[curr + i] >= max) {
          next = curr + i;
          max = i + nums[curr + i];
        }
      }
      res++;
      curr = next;
    }

    return res;
  }
};