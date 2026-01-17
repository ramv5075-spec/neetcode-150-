// NeetCode 150 - Binary Search
// Problem: Binary Search
// Difficulty: Easy
// Approach: Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(target==nums[mid]){
                return mid;
            } else if(nums[mid]<target){
                low=mid+1;
            } else if(nums[mid]>target){
                high=mid-1;
            }
        }
        return -1;
    }
};


