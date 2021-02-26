/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
  ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode *cur = head, *next = nullptr;
    while (cur) {
      next = cur->next;
      while (next && (next->val == cur->val)) {
        ListNode *temp = next;
        cur->next = next->next;
        next = next->next;
        delete (temp);
      }
      cur = cur->next;
    }
    return head;
  }
};
// @lc code=end
