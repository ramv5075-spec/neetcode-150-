// NeetCode 150 - Two Pointers
// Problem: Trapping Rain Water
// Difficulty: Hard
// Approach: Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int lmax = 0, rmax = 0;
        int total = 0;

        while (l < r) {
            if (height[l] <= height[r]) {
                if (lmax > height[l]) {
                    total += lmax - height[l];
                } else {
                    lmax = height[l];
                }
                l = l + 1;
            } else {
                if (rmax > height[r]) {
                    total += rmax - height[r];
                } else {
                    rmax = height[r];
                }
                r = r - 1;
            }
        }
        return total;
    }
};
