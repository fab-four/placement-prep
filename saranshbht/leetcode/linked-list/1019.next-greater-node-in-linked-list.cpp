/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/next-greater-node-in-linked-list/
 */

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
  vector<int> nextLargerNodes(ListNode *head) {
    // "stack" stores indices
    vector<int> res, stack;
    ListNode *current = head;
    while (current) {
      while (stack.size() && res[stack.back()] < current->val) {
        res[stack.back()] = current->val;
        stack.pop_back();
      }
      stack.push_back(res.size());
      res.push_back(current->val);
      current = current->next;
    }
    for (int &i : stack)
      res[i] = 0;
    return res;
  }
};
