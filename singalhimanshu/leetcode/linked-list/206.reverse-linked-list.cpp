// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/reverse-linked-list/
/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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

ListNode *reverseListRec(ListNode *prev, ListNode *cur) {
  if (cur == nullptr) {
    return prev;
  }
  ListNode *next = cur->next;
  cur->next = prev;
  return reverseListRec(cur, next);
}

ListNode *reverseListIt(ListNode *head) {
  ListNode *prev = nullptr;
  ListNode *cur = head;
  ListNode *next = nullptr;
  while (cur) {
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  return prev;
}

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    return reverseListRec(nullptr, head);
    // return reverseListIt(head);
  }
};
// @lc code=end
