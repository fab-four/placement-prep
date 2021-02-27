/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/split-linked-list-in-parts/
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
  vector<ListNode *> splitListToParts(ListNode *root, int k) {
    int size = 0;
    ListNode *current = root;
    while (current) {
      size++;
      current = current->next;
    }

    current = root;
    vector<ListNode *> res;
    while (current) {
      int total = size / k + !!(size % k);
      res.push_back(current);
      for (int i = 1; i < total; i++)
        current = current->next;
      ListNode *temp = current->next;
      current->next = NULL;
      current = temp;
      size -= total;
      k--;
    }
    while (k--) {
      res.push_back(NULL);
    }
    return res;
  }
};