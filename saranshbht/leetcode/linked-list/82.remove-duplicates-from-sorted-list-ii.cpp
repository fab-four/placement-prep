/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
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
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head || !head->next)
      return head;

    ListNode root(0, head);

    ListNode *previous = &root, *current = head;
    while (current && current->next) {
      bool flag = false;
      while (current && current->next && current->val == current->next->val) {
        flag = true;
        previous->next = current->next;
        delete current;
        current = previous->next;
      }
      if (flag) {
        previous->next = current->next;
        delete current;
        current = previous->next;
      } else {
        previous = current;
        current = current->next;
      }
    }
    return root.next;
  }
};
