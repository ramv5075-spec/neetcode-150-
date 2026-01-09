// NeetCode 150 - Two Pointers
// Problem: Two Sum II - Input Array Is Sorted
// Difficulty: Medium
// Approach: Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while (i <= j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                return {i + 1, j + 1};
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
        return {};
    }
};
