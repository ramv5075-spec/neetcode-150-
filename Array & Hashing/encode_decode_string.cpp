// NeetCode 150 - Arrays & Hashing
// Problem: Encode and Decode Strings
// Difficulty: Medium
// Approach: Length Encoding with Delimiter
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string encode(vector<string>& strs) {
        string result;
        for (const string& s : strs) {
            result += to_string(s.size()) + "#" + s;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;

        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }

            int length = stoi(s.substr(i, j - i));
            i = j + 1;

            result.push_back(s.substr(i, length));
            i += length;
        }
        return result;
    }
};
