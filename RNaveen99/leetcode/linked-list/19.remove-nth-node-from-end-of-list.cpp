/**
 * Author: Naveen Rohilla
 * User: RNaveen99
 * Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        
        int index = 0;
        while (index <= n) {
            fast = fast -> next;
            index++;
        }
        while (fast != NULL) {
            slow = slow -> next;
            fast = fast -> next;
        }
        slow -> next = slow -> next -> next;
        return dummy -> next;
    }
};
