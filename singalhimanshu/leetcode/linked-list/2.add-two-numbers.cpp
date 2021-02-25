// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/add-two-numbers/
/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
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
    int carry = 0;
    ListNode *result = nullptr;
    ListNode *result_head = nullptr;
    while (l1 != nullptr || l2 != nullptr) {
      int sum = carry;
      if (l1) {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        sum += l2->val;
        l2 = l2->next;
      }
      carry = sum / 10;
      sum %= 10;
      if (result == nullptr) {
        result = new ListNode(sum);
        result_head = result;
      } else {
        result->next = new ListNode(sum);
        result = result->next;
      }
    }
    if (carry) {
      result->next = new ListNode(carry);
      result = result->next;
    }
    return result_head;
  }
};
// @lc code=end
