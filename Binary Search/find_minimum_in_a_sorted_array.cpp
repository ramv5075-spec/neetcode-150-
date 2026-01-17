// NeetCode 150 - Binary Search
// Problem: Find Minimum in Rotated Sorted Array
// Difficulty: Medium
// Approach: Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int result = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[low] <= nums[mid]) {
                result = min(result, nums[low]);
                low = mid + 1;
            } else {
                result = min(result, nums[mid]);
                high = mid - 1;
            }
        }

        return result;
    }
};
