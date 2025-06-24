#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  bool canJump(vector<int> &nums) {

    if (nums.size() == 1)
      return true;

    vector<bool> visited(nums.size(), false);

    // max, cur size
    queue<pair<int, int>> q;

    q.push({nums[0], 0});
    visited[0] = true;

    while (!q.empty()) {
      int max = q.front().first;
      int cur = q.front().second;
      q.pop();

      if (max == 0)
        continue;
      if (cur == nums.size() - 1 || cur + max >= nums.size() - 1)
        return true;

      for (int i = cur + 1; i < cur + max + 1; ++i) {
        if (!visited[i]) {
          q.push({nums[i], i});
          visited[i] = true;
        }
      }
    }
    return false;
  }

  bool canJump_greedy(vector<int> &nums) {

    int goal = nums.size() - 1;

    for (int i = nums.size() - 1; i >= 0; --i) {
      if (i + nums[i] >= goal)
        goal = i;
    }

    return goal == 0;
  }

  class Solution {
  public:
    bool canJump(vector<int> &nums) {

      int curr = 0;
      int last = nums.size() - 1;

      while (curr < nums.size() && nums[curr] != 0) {
        int c_j = nums[curr];

        if (last - curr <= c_j)
          return true;

        int can_reach = 0;
        int next_pos = curr;

        for (int i = 1; i <= c_j; ++i) {
          if (can_reach <= i + nums[curr + i]) {
            can_reach = i + nums[curr + i];
            next_pos = curr + i;
          }
        }
        curr = next_pos;
      }

      return curr >= last;
    }
  };
};