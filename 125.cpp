#include <string>

using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {

    transform(s.begin(), s.end(), s.begin(), [](char c) { return tolower(c); });

    s.erase(remove_if(s.begin(), s.end(),
                      [](char c) {
                        return !((c >= 'a' && c <= 'z') ||
                                 (c >= '0' && c <= '9'));
                      }),
            s.end());

    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
      if (s[left] != s[right]) {
        return false;
      }
      left++;
      right--;
    }
    return true;
  }
};