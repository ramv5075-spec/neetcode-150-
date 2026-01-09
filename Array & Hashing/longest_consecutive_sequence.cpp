// NeetCode 150 - Arrays & Hashing
// Problem: Longest Consecutive Sequence
// Difficulty: Medium
// Approach: Hash Set + sequence start detection
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 1;

        for (int num : st) {
            // Only start counting if this is the beginning of a sequence
            if (st.find(num - 1) == st.end()) {
                int current = num;
                int count = 1;

                while (st.find(current + 1) != st.end()) {
                    current++;
                    count++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};
