/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/rotate-list/
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
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head || !head->next || !k)
      return head;

    int total = 1;
    ListNode *tail = head;
    while (tail->next) {
      total++;
      tail = tail->next;
    }
    k %= total;
    if (!k)
      return head;

    int idx = 1;
    ListNode *current = head;
    while (idx + k < total) {
      idx++;
      current = current->next;
    }
    ListNode *temp = current->next;
    current->next = NULL;
    tail->next = head;
    return temp;
  }
};