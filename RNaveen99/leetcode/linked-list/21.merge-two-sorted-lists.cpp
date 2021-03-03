/**
 * Author: Naveen Rohilla
 * User:   RNaveen99
 * Link:   https://leetcode.com/problems/merge-two-sorted-lists/
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while (l1 && l2) {
            if (l1 -> val <= l2 -> val) {
                tail -> next = l1;
                tail = tail -> next;
                l1 = l1 -> next;
            } else {
                tail -> next = l2;
                tail = tail -> next;
                l2 = l2 -> next;
            }
        }
        tail -> next = l1 ? l1 : l2;
        return dummy -> next;
    }
};
