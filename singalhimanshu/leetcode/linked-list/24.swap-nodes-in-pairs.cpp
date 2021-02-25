// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/swap-nodes-in-pairs/
/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
  ListNode *swapPairs(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *dummy = new ListNode(-1, head);
    ListNode *prev = dummy;
    ListNode *cur = head;
    while (cur && cur->next) {
      prev->next = cur->next;
      cur->next = cur->next->next;
      prev->next->next = cur;
      prev = prev->next->next;
      cur = cur->next;
    }
    return dummy->next;
  }
};
// @lc code=end
