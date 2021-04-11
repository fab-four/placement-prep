/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/reverse-nodes-in-k-group/
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
    ListNode *reverseSublist(ListNode *head, int k) {
        ListNode *prev = head;
        ListNode *curr = prev->next;

        ListNode *startNode = curr;
        while (k--) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        startNode->next->next = prev;
        startNode->next = curr;

        return startNode;
    }
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy;
        int count = 0;
        while (head) {
            head = head->next;
            count++;
        }
        while (count >= k) {
            prev = reverseSublist(prev, k);
            count -= k;
        }
        return dummy->next;
    }
};