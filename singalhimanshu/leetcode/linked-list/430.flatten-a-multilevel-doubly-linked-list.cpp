// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
/*
 * @lc app=leetcode id=430 lang=cpp
 *
 * [430] Flatten a Multilevel Doubly Linked List
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
  Node *flatten(Node *head) {
    if (head == nullptr) {
      return nullptr;
    }
    Node *cur = head;
    while (cur) {
      Node *next = cur->next;
      if (cur->child) {
        cur->child->prev = cur;
        Node *flattened_list_head = flatten(cur->child);
        cur->next = flattened_list_head;
        cur->child = nullptr;
        if (next) {
          Node *flattened_list_last_node = last(flattened_list_head);
          flattened_list_last_node->next = next;
          next->prev = flattened_list_last_node;
        }
      }
      cur = next;
    }
    return head;
  }
  Node *last(Node *node) {
    while (node->next) {
      node = node->next;
    }
    return node;
  }
};
// @lc code=end
