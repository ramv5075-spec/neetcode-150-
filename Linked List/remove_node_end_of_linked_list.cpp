// NeetCode 150 - Linked List
// Problem: Remove Nth Node From End of List
// Difficulty: Medium
// Approach: Two Pass (Length Calculation)
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <cstddef>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return nullptr;

        ListNode* temp = head;
        int count = 0;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        if (count == n) {
            ListNode* newHead = head->next;
            return newHead;
        }

        temp = head;
        for (int i = 1; i < count - n; i++) {
            temp = temp->next;
        }

        temp->next = temp->next->next;

        return head;
    }
};
