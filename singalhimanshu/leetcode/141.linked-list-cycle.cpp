// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/linked-list-cycle/
/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
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
  bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return false;
    }
    ListNode *slow_ptr = head;
    ListNode *fast_ptr = head;
    while (fast_ptr != nullptr && fast_ptr->next != nullptr) {
      fast_ptr = fast_ptr->next->next;
      slow_ptr = slow_ptr->next;
      if (fast_ptr == slow_ptr) {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end
