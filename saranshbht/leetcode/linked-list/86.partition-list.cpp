/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/partition-list/
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
  ListNode *partition(ListNode *head, int x) {
    if (!head || !head->next)
      return head;

    ListNode *current = head;
    ListNode *l_head = NULL, *r_head = NULL, *l_current = NULL,
             *r_current = NULL;
    while (current) {
      if (current->val < x) {
        if (!l_head) {
          l_head = l_current = current;
        } else {
          l_current = l_current->next = current;
        }
      } else {
        if (!r_head) {
          r_head = r_current = current;
        } else {
          r_current = r_current->next = current;
        }
      }
      current = current->next;
    }
    if (l_current) {
      l_current->next = NULL;
    }
    if (r_current) {
      r_current->next = NULL;
    }

    if (!l_head)
      return r_head;
    l_current->next = r_head;
    return l_head;
  }
};
