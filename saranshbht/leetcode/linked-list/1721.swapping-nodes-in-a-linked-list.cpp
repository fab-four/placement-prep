/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
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
  ListNode *swapNodes(ListNode *head, int k) {
    if (!head || !head->next)
      return head;

    int idx = 1;
    ListNode *current = head;
    ListNode *current2 = head;
    while (idx < k) {
      idx++;
      current = current->next;
    }
    ListNode *current1 = current;
    while (current1->next) {
      current1 = current1->next;
      current2 = current2->next;
    }
    if (current->val != current2->val)
      current->val ^= current2->val ^= current->val ^= current2->val;

    return head;
  }
};