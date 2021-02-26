/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/remove-linked-list-elements/
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
  ListNode *removeElements(ListNode *head, int val) {
    ListNode root(0, head);
    ListNode *previous = &root;
    while (previous->next) {
      if (previous->next->val == val) {
        ListNode *temp = previous->next;
        previous->next = temp->next;
        delete temp;
      } else {
        previous = previous->next;
      }
    }
    return root.next;
  }
};