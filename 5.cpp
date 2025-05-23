#include <string>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {

    int start = 0;
    int maxlen = 0;

    for (int i = 0; i < s.length(); ++i) {

      int from_odd = expand(i, i, s);
      int from_even = expand(i, i + 1, s);

      int m = max(from_odd, from_even);
      if (maxlen <= m) {
        start = i;
        maxlen = m;
      }
    }

    return s.substr(start - ((maxlen - 1) / 2), maxlen);
  }

  int expand(int left, int right, string &str) {
    while (left >= 0 && right < str.length() && str[left] == str[right]) {
      left--;
      right++;
    }
    return right - left - 1;
  }
};