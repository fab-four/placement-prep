/**
 * Author: Naveen Rohilla
 * User: RNaveen99
 * Link: https://leetcode.com/problems/reverse-linked-list-ii/
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        
        ListNode* prev = NULL;
        ListNode* curr = dummy;
        ListNode* nextNode = NULL;

        for (int i = 0; i < left; i++) {
            prev = curr;
            curr = curr -> next;
        }
        ListNode* startNode = curr;
        while (left++ <= right) {
            nextNode = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextNode;
        }
        startNode -> next -> next = prev;
        startNode -> next = curr;
        
        return dummy -> next;
    }
};
