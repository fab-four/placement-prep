/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/reverse-nodes-in-k-group/
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
  ListNode *reverseKGroup(ListNode *head, int k) {
    // With size
    // if (!head || !head->next || k == 1)
    //   return head;

    // int total = 1;
    // ListNode *current = head;
    // while (current) {
    //   current = current->next;
    //   total++;
    // }

    // current = head;
    // ListNode root;
    // ListNode *previousTail = &root;
    // while (total > k) {
    //   ListNode *kHead = current;
    //   ListNode *previous = NULL;
    //   for (int i = 0; i < k; i++) {
    //     ListNode *next = current->next;
    //     current->next = previous;
    //     previous = current;
    //     current = next;
    //   }
    //   kHead->next = current;
    //   previousTail->next = previous;
    //   previousTail = kHead;
    //   total -= k;
    // }
    // return root.next;

    // Without size
    if (!head || !head->next || k == 1)
      return head;

    ListNode *current = head;
    ListNode *nextKHead = head;
    for (int i = 0; i < k; i++)
      nextKHead = nextKHead->next;

    ListNode root;
    ListNode *previous = &root, *previousTail = &root;
    bool flag = true;
    while (flag) {
      ListNode *currentKHead = current;
      for (int i = 0; i < k; i++) {
        ListNode *next = current->next;
        current->next = previous;
        previous = current;
        current = next;
        if (nextKHead) {
          nextKHead = nextKHead->next;
        } else {
          flag = false;
        }
      }
      currentKHead->next = current;
      previousTail->next = previous;
      previousTail = currentKHead;
    }
    return root.next;
  }
};