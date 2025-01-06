
#include <algorithm>
#include <vector>


class Solution {
public:
    int rob(std::vector<int>& nums) {

        int rob1 = 0;
        int rob2 = 0;

        for (int num : nums) {
            
            int temp = std::max(rob1 + num, rob2);
            rob1 = rob2;
            rob2 = temp;
        }


        return rob2;

    }
};