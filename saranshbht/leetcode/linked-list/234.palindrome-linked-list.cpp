/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/palindrome-linked-list/
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
  bool isPalindrome(ListNode *head) {
    if (!head || !head->next)
      return true;

    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }

    if (fast)
      slow = slow->next;
    slow = reverseList(slow);

    while (slow && head) {
      if (slow->val != head->val)
        return false;
      slow = slow->next;
      head = head->next;
    }
    return true;
  }

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
  }
};