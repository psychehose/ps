#include <vector>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string res;

        for (const auto& c : strs) {
            res += to_string(c.size()) + "#" + c;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;

        while(i < s.size()) {
            int j = i;

            while(s[j] != '#') {
                ++j;
            }
            
            int len = stoi(s.substr(i, j-i));

            string sub = s.substr(j+1, len);

            res.push_back(sub);
            i = j + len + 1;
        }
        return res;
    }
};
