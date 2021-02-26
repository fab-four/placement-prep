/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/intersection-of-two-linked-lists/
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB)
      return NULL;

    ListNode *currentA = headA, *currentB = headB;
    while (currentA != currentB) {
      currentA = currentA ? currentA->next : headB;
      currentB = currentB ? currentB->next : headA;
    }
    return currentA;
  }
}