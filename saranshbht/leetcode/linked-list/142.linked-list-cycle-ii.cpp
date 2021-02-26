/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/linked-list-cycle-ii/
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
  ListNode *detectCycle(ListNode *head) {
    if (!head || !head->next)
      return NULL;

    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *start = head;

    while (fast) {
      if (!fast->next) {
        return NULL;
      } else {
        slow = slow->next;
        fast = fast->next->next;
      }
      if (slow == fast) {
        while (slow != start) {
          slow = slow->next;
          start = start->next;
        }
        return slow;
      }
    }
    return NULL;
  }
};