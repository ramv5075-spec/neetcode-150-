// NeetCode 150 - Linked List (Cycle / Fast & Slow Pointer)
// Problem: Find the Duplicate Number
// Difficulty: Medium
// Approach: Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        for (auto it : mp) {
            if (it.second > 1) {
                return it.first;
            }
        }

        return -1; // safety return (will never hit as per problem constraints)
    }
};
