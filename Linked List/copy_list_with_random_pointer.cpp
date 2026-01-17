// NeetCode 150 - Linked List
// Problem: Copy List with Random Pointer
// Difficulty: Medium
// Approach: Interweaving Nodes (O(1) Extra Space)
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <cstddef>
using namespace std;

/**
 * Definition for a Node.
 */
struct Node {
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        Node* current = head;

        // Step 1: Insert copied nodes after original nodes
        while (current != nullptr) {
            Node* newNode = new Node(current->val);
            newNode->next = current->next;
            current->next = newNode;
            current = newNode->next;
        }

        // Step 2: Assign random pointers
        current = head;
        while (current != nullptr) {
            if (current->random != nullptr) {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }

        // Step 3: Separate the two lists
        current = head;
        Node* newHead = head->next;
        Node* newCurrent = newHead;

        while (current != nullptr) {
            current->next = newCurrent->next;
            current = current->next;

            if (current != nullptr) {
                newCurrent->next = current->next;
                newCurrent = current->next;
            }
        }

        return newHead;
    }
};
