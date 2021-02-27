/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/insertion-sort-list/
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
  ListNode *insertionSortList(ListNode *head) {
    if (!head || !head->next)
      return head;

    ListNode root(0, head);
    ListNode *rootptr = &root;
    ListNode *previous = head;
    ListNode *current = head->next;
    while (current) {
      if (current->val < previous->val) {
        while (rootptr->next->val <= current->val) {
          rootptr = rootptr->next;
        }
        previous->next = current->next;
        current->next = rootptr->next;
        rootptr->next = current;

        current = previous->next;
        rootptr = &root;
      } else {
        previous = current;
        current = current->next;
      }
    }
    return root.next;
  }
};
