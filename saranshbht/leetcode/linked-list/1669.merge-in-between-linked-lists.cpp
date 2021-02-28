/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/merge-in-between-linked-lists/
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
  ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {

    ListNode *current = list1;
    int cnt = 1;
    while (cnt < a) {
      current = current->next;
      cnt++;
    }
    ListNode *tail_list2 = current;
    current = current->next;

    tail_list2->next = list2;
    while (tail_list2->next) {
      tail_list2 = tail_list2->next;
    }

    while (cnt <= b) {
      ListNode *temp = current;
      current = current->next;
      delete temp;
      cnt++;
    }
    tail_list2->next = current;
    return list1;
  }
};