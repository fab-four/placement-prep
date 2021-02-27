/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/add-two-numbers-ii/
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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int size1 = 0;
    int size2 = 0;

    ListNode *previous = NULL, *node = NULL;
    ListNode *current1 = l1, *current2 = l2;
    while (current1) {
      size1++;
      current1 = current1->next;
    }
    while (current2) {
      size2++;
      current2 = current2->next;
    }

    while (l1 || l2) {
      int value1 = 0, value2 = 0;
      if (size1 > size2) {
        size1--;
        value1 = l1->val;
        l1 = l1->next;
      } else if (size2 > size1) {
        size2--;
        value2 = l2->val;
        l2 = l2->next;
      } else {
        value1 = l1->val;
        value2 = l2->val;
        l1 = l1->next;
        l2 = l2->next;
      }

      // create list in reverse, i.e. least significant digit first
      node = new ListNode(value1 + value2);
      node->next = previous;
      previous = node;
    }

    // adjust carry and reverse list
    int carry = 0;
    previous = NULL;
    while (node) {
      node->val += carry;
      carry = node->val / 10;
      node->val %= 10;

      ListNode *temp = node->next;
      node->next = previous;
      previous = node;
      node = temp;
    }

    if (carry) {
      ListNode *temp = new ListNode(carry);
      temp->next = previous;
      previous = temp;
    }
    return previous;
  }
};