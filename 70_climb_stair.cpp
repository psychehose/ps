#include <vector>

class Solution {
public:
    int climbStairs(int n) {
           std::vector<int> dp { 1, 2 };
           dp.reserve(n);

           for (int i = 2; i < n; ++i) {
            dp.push_back(2 *dp[i-1] + 2 * dp[i-2]);
           }

           return *(dp.end() - 1);
    }
};