/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   :
 * https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
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
  ListNode *removeZeroSumSublists(ListNode *head) {
    ListNode root(0, head);
    ListNode *current = &root;
    int prefixSum = 0;
    unordered_map<int, ListNode *> mp;

    while (current) {
      prefixSum += current->val;
      if (mp.count(prefixSum)) {
        ListNode *removeNext = mp[prefixSum];
        int tempPrefixSum = prefixSum + removeNext->next->val;
        while (tempPrefixSum != prefixSum) {
          mp.erase(tempPrefixSum);
          removeNext = removeNext->next;
          tempPrefixSum += removeNext->next->val;
        }
        mp[prefixSum]->next = current->next;
      } else {
        mp[prefixSum] = current;
      }
      current = current->next;
    }
    return root.next;
  }
};