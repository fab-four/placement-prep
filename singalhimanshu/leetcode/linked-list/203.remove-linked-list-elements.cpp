// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/remove-linked-list-elements/
/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
  ListNode *removeElements(ListNode *head, int val) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode *dummy = new ListNode(-1, head);
    ListNode *cur = head;
    ListNode *prev = nullptr;
    while (cur) {
      if (cur->val == val) {
        ListNode *temp = cur;
        if (prev) {
          prev->next = cur->next;
        }
        cur = cur->next;
        delete temp;
      } else {
        prev = cur;
        cur = cur->next;
      }
      if (prev == nullptr) {
        dummy->next = cur;
      }
    }
    return dummy->next;
  }
};
// @lc code=end
