// NeetCode 150 - Two Pointers
// Problem: Valid Palindrome
// Difficulty: Easy
// Approach: Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,j=s.length()-1;
        while(i<=j){
            if(isalnum(s[i])==0){
                i++;
                continue;
            }
            if(isalnum(s[j])==0){
                j--;
                continue;
            }
            if(tolower(s[i])!=tolower(s[j])){
                return false;
            } else {
                i++;
                j--;
            }
        }    
        return true;
    }
};
