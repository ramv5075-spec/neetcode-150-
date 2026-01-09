// NeetCode 150 - Two Pointers
// Problem: Container With Most Water
// Difficulty: Medium
// Approach: Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size() - 1, maxArea = 0;
        while (left < right) {
            int area = min(heights[left], heights[right]) * (right - left);
            maxArea = max(area, maxArea);
            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
};
