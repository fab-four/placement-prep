// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/merge-two-sorted-lists/
/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr) {
      return l2;
    }
    if (l2 == nullptr) {
      return l1;
    }
    if (l1 == nullptr && l2 == nullptr) {
      return nullptr;
    }
    ListNode *merged_list_ptr = new ListNode(-1);
    ListNode *merged_list_head = merged_list_ptr;
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val <= l2->val) {
        merged_list_ptr->next = l1;
        l1 = l1->next;
      } else {
        merged_list_ptr->next = l2;
        l2 = l2->next;
      }
      merged_list_ptr = merged_list_ptr->next;
    }
    while (l1 != nullptr) {
      merged_list_ptr->next = l1;
      merged_list_ptr = merged_list_ptr->next;
      l1 = l1->next;
    }
    while (l2 != nullptr) {
      merged_list_ptr->next = l2;
      merged_list_ptr = merged_list_ptr->next;
      l2 = l2->next;
    }
    return merged_list_head->next;
  }
};
// @lc code=end
