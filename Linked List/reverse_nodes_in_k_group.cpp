// NeetCode 150 - Linked List
// Problem: Reverse Nodes in k-Group
// Difficulty: Hard
// Approach: Reverse Each k-Group Iteratively
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
    ListNode* getkthNode(ListNode* temp, int k) {
        k -= 1;
        while (temp != nullptr && k > 0) {
            temp = temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while (temp != nullptr) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k <= 1) return head;

        ListNode* temp = head;
        ListNode* prevLast = nullptr;

        while (temp != nullptr) {
            ListNode* kthNode = getkthNode(temp, k);

            if (kthNode == nullptr) {
                if (prevLast) {
                    prevLast->next = temp;
                }
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = nullptr;

            ListNode* newHead = reverseList(temp);

            if (temp == head) {
                head = newHead;
            } else {
                prevLast->next = newHead;
            }

            prevLast = temp;
            temp = nextNode;
        }

        return head;
    }
};
