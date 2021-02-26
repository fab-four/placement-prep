/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/middle-of-the-linked-list/
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
  ListNode *middleNode(ListNode *head) {
    int total = 0;
    ListNode *current = head;
    while (current) {
      total++;
      current = current->next;
    }
    total >>= 1;
    current = head;
    while (total--) {
      head = head->next;
    }
    return head;
  }
};