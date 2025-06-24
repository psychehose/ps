class Solution {
public:
  int maxDistance(string s, int k) {

    int x = 0;
    int y = 0;

    vector<int> dist_at_point;

    for (const auto &c : s) {
      if (c == 'N')
        y++;
      else if (c == 'E')
        x++;
      else if (c == 'W')
        x--;
      else if (c == 'S')
        y--;
      dist_at_point.push_back(abs(x) + abs(y));
    }

    if (k == 0) {
      return *max_element(dist_at_point.begin(), dist_at_point.end());
    }

    // each point에서 값 수정

    int max_dist = dist_at_point[1];
    int prev = dist_at_point[0];
    int by_change = 0;

    for (int i = 1; i < dist_at_point.size(); ++i) {
      if (dist_at_point[i] < prev && k > 0) {
        k--;
        by_change += 2; // k를 쓴다는 것은 하나 줄이고 하나 느는거임.
      }
      prev = dist_at_point[i];
      dist_at_point[i] += by_change;
      max_dist = max(max_dist, dist_at_point[i]);
    }

    return max_dist;
  }
};