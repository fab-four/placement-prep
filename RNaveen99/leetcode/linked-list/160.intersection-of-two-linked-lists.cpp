/**
 * Author: Naveen Rohilla
 * User: RNaveen99
 * Link: https://leetcode.com/problems/intersection-of-two-linked-lists/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *h1 = headA;
        ListNode *h2 = headB;
        
        while (h1 != h2) {
            h1 = h1 ? h1->next : headB;
            h2 = h2 ? h2->next : headA;
        }
        return h1;
    }
};
