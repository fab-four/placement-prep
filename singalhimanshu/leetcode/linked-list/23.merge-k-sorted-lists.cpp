/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.empty()) {
      return nullptr;
    }
    size_t list_len = lists.size();
    while (list_len > 1) {
      for (size_t i = 0; i < list_len / 2; i++) {
        lists[i] = mergeTwoLists(lists[i], lists[list_len - i - 1]);
      }
      list_len = (list_len + 1) / 2;
    }
    return lists.front();
  }
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
    if (l1) {
      merged_list_ptr->next = l1;
    } else if (l2) {
      merged_list_ptr->next = l2;
    }
    return merged_list_head->next;
  }
};
// @lc code=end
