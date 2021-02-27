// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/copy-list-with-random-pointer/
/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
  Node *copyRandomList(Node *head) {
    if (head == nullptr) {
      return nullptr;
    }
    Node *cur = head, *cur_copy = nullptr, *copy_head = nullptr;
    while (cur) {
      cur_copy = new Node(cur->val, cur->next, nullptr);
      cur->next = cur_copy;
      cur = cur_copy->next;
    }
    cur = head;
    while (cur) {
      cur_copy = cur->next;
      if (cur->random) {
        cur_copy->random = cur->random->next;
      }
      cur = cur_copy->next;
    }
    cur = head;
    copy_head = cur->next;
    while (cur) {
      cur_copy = cur->next;
      cur->next = cur_copy->next;
      cur = cur->next;
      if (cur) {
        cur_copy->next = cur->next;
      }
    }
    return copy_head;
  }
};
// @lc code=end
