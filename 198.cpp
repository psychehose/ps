#include <vector>

using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();

    if (n == 1) {
      return nums[0];
    }
    vector<int> dp(nums.size(), 0);

    dp[0] = nums[0];
    dp[1] = nums[0] >= nums[1] ? nums[0] : nums[1];

    // dp[k] = dp[k-1] or dp[k-2] + nums[k]

    for (int i = 2; i < nums.size(); ++i) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[dp.size() - 1];
  }
};