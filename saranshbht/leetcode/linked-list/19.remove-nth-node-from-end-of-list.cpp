/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    // Two pass
    // int total = 0;
    // ListNode *current = head;
    // while (current) {
    //   total++;
    //   current = current->next;
    // }
    // if (total == n) {
    //   current = head->next;
    //   delete head;
    //   return current;
    // }
    // int idx = 1;
    // current = head;
    // while (idx + n < total) {
    //   idx++;
    //   current = current->next;
    // }
    // ListNode *temp = current->next;
    // current->next = temp->next;
    // delete temp;
    // return head;

    // One pass
    ListNode *current1 = head;
    while (n--) {
      current1 = current1->next;
    }
    if (!current1) {
      ListNode *temp = head;
      head = head->next;
      delete temp;
      return head;
    }
    ListNode *current2 = head;
    while (current1->next) {
      current1 = current1->next;
      current2 = current2->next;
    }

    ListNode *temp = current2->next;
    current2->next = temp->next;
    delete temp;
    return head;
  }
};