/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/reverse-linked-list-ii/
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
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (!head || !head->next)
      return head;

    ListNode root(0, head);
    ListNode *previous = &root;
    int i;
    for (i = 1; i < left; i++) {
      previous = previous->next;
    }

    ListNode *current = previous->next;
    ListNode *temp = previous;
    while (current && i <= right) {
      ListNode *next = current->next;
      current->next = previous;
      previous = current;
      current = next;
      i++;
    }
    temp->next->next = current;
    temp->next = previous;

    return root.next;
  }
};