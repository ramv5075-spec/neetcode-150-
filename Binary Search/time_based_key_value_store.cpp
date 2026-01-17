// NeetCode 150 - Binary Search
// Problem: Time Based Key-Value Store
// Difficulty: Medium
// Approach: Hash Map + Binary Search
// Time Complexity: O(log n) for get, O(1) for set
// Space Complexity: O(n)

#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) { 
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>>& p = mp[key];
        int left = 0, right = p.size() - 1;
        string result = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (p[mid].first == timestamp) {
                return p[mid].second;
            }
            if (p[mid].first <= timestamp) {
                result = p[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;    
    }
};
