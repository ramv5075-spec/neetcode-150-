// NeetCode 150 - Arrays & Hashing
// Problem: Valid Anagram
// Difficulty: Easy
// Approach: Hash Map (Frequency Count)
// Time Complexity: O(n)
// Space Complexity: O(1)  // since only 26 lowercase letters

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> mp;

        for (char c : s) {
            mp[c]++;
        }

        for (char c : t) {
            mp[c]--;
            if (mp[c] < 0) return false;
        }

        return true;
    }
};
