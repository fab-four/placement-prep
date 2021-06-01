/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/linked-list-components/
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
    int numComponents(ListNode *head, vector<int> &nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int connected = 0;
        int count = 0;
        while (head) {
            if (s.find(head->val) != s.end()) {
                if (count == 0) {
                    connected++;
                }
                count++;
            } else {
                count = 0;
            }
            head = head->next;
        }
        return connected;
    }
};