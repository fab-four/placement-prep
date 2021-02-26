// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/rotate-list/
/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
  ListNode *rotateRight(ListNode *head, int k) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode *tail = head;
    int list_size = 1;
    while (tail->next) {
      list_size++;
      tail = tail->next;
    }
    k %= list_size;
    if (k == 0) {
      return head;
    }
    tail->next = head;
    ListNode *new_tail = head, *new_head = nullptr;
    for (int i = 1; i < (list_size - k); i++) {
      new_tail = new_tail->next;
    }
    new_head = new_tail->next;
    new_tail->next = nullptr;
    return new_head;
  }
};
// @lc code=end
