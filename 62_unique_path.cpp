
#include <vector>

class Solution {
public:

    int uniquePaths(int m, int n) {

        // dp 초기화
        std::vector<std::vector<int>> dp(m, std::vector<int>(n,1));

        for (std::vector<std::vector<int>>::size_type r = 1; r < dp.size(); ++r) {
            for (std::vector<int>::size_type c = 1; c < dp[r].size(); ++c) {
                dp[r][c] = dp[r-1][c] + dp[r][c-1];
            }
        }

        return dp[m-1][n-1];
    }
};