#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> countmap;
        
        int res = 0;
        int l = 0;

        for (int r = 0; r < s.size(); ++r) {
            countmap[s[r]] = 1 + countmap[s[r]];

            while((r - l + 1) - most_frequent(countmap) > k) {
                countmap[s[l]] = countmap[s[l]] - 1;
                l += 1; 
            }

            res = max(res, r - l + 1);
        }
    }

    int characterReplacement_opt(string s, int k) {
        unordered_map<char, int> countmap;
        int l = 0;
        int max_len = 0;
        int max_count = 0;

        for (int r = 0; r < s.size(); ++r) {
            countmap[s[r]] = countmap[s[r]] + 1;
            max_count = max(max_count, countmap[s[r]]);

            while((r - l + 1) - max_count > k) {
                countmap[s[l]] = countmap[s[l]] - 1;
                l += 1; 
            }
             max_len = max(max_len, r-l+1);
        }

        return max_len;
    }



    int most_frequent(unordered_map<char, int>& m) {
        int frequent = 0;

        for (auto& [k, v] : m) {
            frequent = max(frequent, v);
        }
    }
};