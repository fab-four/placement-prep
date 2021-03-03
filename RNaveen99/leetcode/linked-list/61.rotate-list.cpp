/**
 * Author: Naveen Rohilla
 * User:   RNaveen99
 * Link:   https://leetcode.com/problems/rotate-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head -> next == NULL) {
            return head;
        }
        ListNode* slow = head;
        int length = 1;
        while (slow -> next) {
            slow = slow -> next;
            length += 1;
        }
        ListNode* tail = slow;
        k = k % length;
        
        slow = head;
        int i = 1;
        while (i++ < length - k) {
            slow = slow -> next;
        }
        tail -> next = head;
        head = slow -> next;
        slow -> next = NULL;
        return head;
        
    }
};
