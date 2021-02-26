/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link  : https://leetcode.com/problems/add-two-numbers/
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
    ListNode root;
    ListNode *current = &root;
    int carry = 0, sum;

    // while (l1 || l2) {
    //   sum = carry;
    //   if (l1) {
    //     sum += l1->val;
    //     l1 = l1->next;
    //   }
    //   if (l2) {
    //     sum += l2->val;
    //     l2 = l2->next;
    //   }
    //   current->next = new ListNode(sum % 10);
    //   current = current->next;
    //   carry = sum / 10;
    // }

    while (l1 && l2) {
      sum = carry + l1->val + l2->val;
      current->next = new ListNode(sum % 10);
      carry = sum / 10;
      l1 = l1->next;
      l2 = l2->next;
      current = current->next;
    }
    while (l1) {
      sum = carry + l1->val;
      current->next = new ListNode(sum % 10);
      carry = sum / 10;
      l1 = l1->next;
      current = current->next;
    }
    while (l2) {
      sum = carry + l2->val;
      current->next = new ListNode(sum % 10);
      carry = sum / 10;
      l2 = l2->next;
      current = current->next;
    }

    if (carry)
      current->next = new ListNode(carry);

    return root.next;
  }
};
