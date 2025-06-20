#include <vector>

class Solution {
public:
  int partitionArray(std::vector<int> &nums, int k) {
    std::sort(nums.begin(), nums.end());

    int res = 1;

    int minvalue = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] - minvalue > k) {
        ++res;
        minvalue = nums[i];
      }
    }

    return res;
  }
};