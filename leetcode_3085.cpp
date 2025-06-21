class Solution {
public:
  int minimumDeletions(string word, int k) {
    vector<int> vec(26, 0); // 알파벳

    for (const auto &c : word) {
      vec[c - 'a'] += 1;
    }
    sort(vec.begin(), vec.end());
    vec.erase(remove(vec.begin(), vec.end(), 0), vec.end());
    int res = numeric_limits<int>::max();

    for (int i = 0; i < vec.size(); ++i) {
      int base = vec[i];
      int deletions = 0;
      for (int j = 0; j < i; ++j) {
        deletions += vec[j];
      }
      for (int j = i + 1; j < vec.size(); ++j) {
        if (vec[j] > base + k) {
          deletions += vec[j] - (base + k);
        }
      }
      res = min(res, deletions);
    }
    return res;
  }
};