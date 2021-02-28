/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/merge-k-sorted-lists/
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
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    int n = lists.size();
    if (n == 0)
      return NULL;
    for (int i = 1; i < n; i *= 2) {
      for (int j = 0; j + i < n; j += 2 * i) {
        ListNode root;
        ListNode *previous = &root;
        ListNode *l1 = lists[j];
        ListNode *l2 = lists[j + i];
        while (l1 && l2) {
          if (l1->val < l2->val) {
            previous = previous->next = l1;
            l1 = l1->next;
          } else {
            previous = previous->next = l2;
            l2 = l2->next;
          }
        }
        if (l1) {
          previous->next = l1;
        } else {
          previous->next = l2;
        }
        lists[j] = root.next;
      }
    }
    return lists[0];
  }
};