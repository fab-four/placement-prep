/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/swap-nodes-in-pairs/
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
  ListNode *swapPairs(ListNode *head) {
    ListNode root;
    ListNode *previous = &root;
    previous->next = head;
    ListNode *current = head;
    while (current && current->next) {
      previous->next = current->next;
      current->next = current->next->next;
      previous->next->next = current;

      previous = current;
      current = current->next;
    }
    return root.next;
  }
};