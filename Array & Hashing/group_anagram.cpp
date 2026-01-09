// NeetCode 150 - Arrays & Hashing
// Problem: Group Anagrams
// Difficulty: Medium
// Approach: Sort each string as key
// Time Complexity: O(n * k log k)
// Space Complexity: O(n * k)

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].push_back(str);
        }

        vector<vector<string>> result;
        for (auto& entry : mp) {
            result.push_back(entry.second);
        }

        return result;
    }
};
