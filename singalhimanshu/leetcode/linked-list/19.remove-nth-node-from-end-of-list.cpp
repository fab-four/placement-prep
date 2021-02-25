// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *slow_ptr = head;
    ListNode *fast_ptr = head;
    ListNode *prev = nullptr;
    for (int i = 0; i < n && fast_ptr; i++) {
      fast_ptr = fast_ptr->next;
    }
    while (fast_ptr) {
      fast_ptr = fast_ptr->next;
      prev = slow_ptr;
      slow_ptr = slow_ptr->next;
    }
    if (prev) {
      prev->next = slow_ptr->next;
    } else {
      head = head->next;
    }
    delete slow_ptr;
    return head;
  }
};
// @lc code=end
