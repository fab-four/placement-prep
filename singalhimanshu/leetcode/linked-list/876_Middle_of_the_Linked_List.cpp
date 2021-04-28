// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/middle-of-the-linked-list/

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
  // Time Complexity : O(n)
  // Space Complexity : O(1)
  ListNode *middleNode(ListNode *head) {
    ListNode *slow_ptr = head;
    ListNode *fast_ptr = head;
    while (fast_ptr && fast_ptr->next) {
      slow_ptr = slow_ptr->next;
      fast_ptr = fast_ptr->next->next;
    }
    return slow_ptr;
  }
};
