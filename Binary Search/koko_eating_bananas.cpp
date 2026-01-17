// NeetCode 150 - Binary Search
// Problem: Koko Eating Bananas
// Difficulty: Medium
// Approach: Binary Search on Answer
// Time Complexity: O(n log m)
// Space Complexity: O(1)

#include <vector>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    int findMax(vector<int> piles) {
        int maxi = INT_MIN;
        for (int i = 0; i < piles.size(); i++) {
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    int calHours(vector<int>& piles, int h) {
        int total = 0;
        for (int i = 0; i < piles.size(); i++) {
            total += ceil((double)piles[i] / (double)h);
        }
        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int totalHours = calHours(piles, mid);

            if (totalHours <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
