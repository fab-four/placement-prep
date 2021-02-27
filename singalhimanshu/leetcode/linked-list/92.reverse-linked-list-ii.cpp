// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/reverse-linked-list-ii/
/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode *dummy = new ListNode(-1, head);
    ListNode *node_before_sublist = findNodeBeforeSublist(dummy, left);
    ListNode *cur = node_before_sublist->next;
    while (left < right) {
      ListNode *next = cur->next;
      cur->next = next->next;
      next->next = node_before_sublist->next;
      node_before_sublist->next = next;
      left++;
    }
    return dummy->next;
  }

  ListNode *findNodeBeforeSublist(ListNode *head, int left) {
    ListNode *node_before_sublist = head;
    for (int i = 1; i < left; i++) {
      node_before_sublist = node_before_sublist->next;
    }
    return node_before_sublist;
  }
};
// @lc code=end
