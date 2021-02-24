// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/linked-list-cycle-ii/
/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
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

ListNode *firstMeetPoint(ListNode *head) {
  if (head == nullptr || head->next == nullptr) {
    return nullptr;
  }
  ListNode *slow_ptr = head;
  ListNode *fast_ptr = head;
  while (fast_ptr != nullptr && fast_ptr->next != nullptr) {
    fast_ptr = fast_ptr->next->next;
    slow_ptr = slow_ptr->next;
    if (fast_ptr == slow_ptr) {
      return fast_ptr;
    }
  }
  return nullptr;
}

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *meet_point = firstMeetPoint(head);
    if (meet_point == nullptr) {
      return meet_point;
    }
    ListNode *node = head;
    while (node != nullptr && meet_point != nullptr) {
      if (node == meet_point) {
        return node;
      }
      node = node->next;
      meet_point = meet_point->next;
    }
    return nullptr;
  }
};
// @lc code=end
