/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/reverse-linked-list/
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
  ListNode *reverseList(ListNode *head) {
    // Iterative
    ListNode *previous = NULL;
    ListNode *current = head;
    while (current) {
      ListNode *next = current->next;
      current->next = previous;
      previous = current;
      current = next;
    }
    return previous;

    // Recursive
    // if (!head || !head->next)
    //   return head;
    // ListNode *newHead = reverseList(head->next);
    // head->next->next = head;
    // head->next = NULL;
    // return newHead;
  }
};