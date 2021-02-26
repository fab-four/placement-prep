/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/odd-even-linked-list/
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
  ListNode *oddEvenList(ListNode *head) {
    if (!head || !head->next)
      return head;
    ListNode *oddCurrent = head, *oddHead = head;
    ListNode *evenCurrent = head->next, *evenHead = head->next;
    bool even = false;
    ListNode *current = evenCurrent->next;
    while (current) {
      if (even) {
        evenCurrent->next = current;
        evenCurrent = evenCurrent->next;
      } else {
        oddCurrent->next = current;
        oddCurrent = oddCurrent->next;
      }
      even = !even;
      current = current->next;
    }
    oddCurrent->next = evenCurrent->next = NULL;
    oddCurrent->next = evenHead;
    return oddHead;
  }
};