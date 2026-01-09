// NeetCode 150 - Arrays & Hashing
// Problem: Top K Frequent Elements
// Difficulty: Medium
// Approach: Bucket Sort (frequency buckets)
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto &p : freq) {
            buckets[p.second].push_back(p.first);
        }

        vector<int> result;
        for (int i = (int)buckets.size() - 1; i >= 0 && (int)result.size() < k; i--) {
            for (int val : buckets[i]) {
                result.push_back(val);
                if ((int)result.size() == k) break;
            }
        }
        return result;
    }
};
