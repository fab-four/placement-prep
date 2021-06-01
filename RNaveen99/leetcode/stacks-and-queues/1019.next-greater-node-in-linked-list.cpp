/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
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
        vector<int> result;
        while (head) {
            result.emplace_back(head->val);
            head = head->next;
        }
        stack<int> s;
        for (int i = result.size() - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= result[i]) {
                s.pop();
            }
            int value;
            if (s.empty()) {
                value = 0;
            } else {
                value = s.top();
            }
            s.emplace(result[i]);
            result[i] = value;
        }
        return result;
    }
};