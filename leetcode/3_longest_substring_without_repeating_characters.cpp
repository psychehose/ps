#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        size_t result = 0;
        string sub_s;

        for (size_t i = 0; i < s.size(); ++i) {
            if (auto p = sub_s.find(s[i]);  p != string::npos) {
                // find
                result = max(result, sub_s.size());
                sub_s.erase(0,p + 1);
            }
            sub_s += s[i];
        }

        return (int)result;
    }

    int lengthOfLongestSubstring_2(string s) {
        unordered_set<char> charSet;
        int l = 0;
        int res = 0;

        for (int r = 0; r < s.size(); r++) {
            while (charSet.find(s[r]) != charSet.end()) {
                charSet.erase(s[l]);
                l++;
            }
            charSet.insert(s[r]);
            res = max(res, r - l + 1);
        }
        return res;
    }
};