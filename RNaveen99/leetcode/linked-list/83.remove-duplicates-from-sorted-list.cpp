/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/remove-duplicates-from-sorted-list/
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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *itr1 = head;

        while (itr1 && itr1->next) {
            ListNode *itr2 = itr1->next;

            while (itr2 && itr1->val == itr2->val) {
                itr2 = itr2->next;
            }
            itr1->next = itr2;
            itr1 = itr1->next;
        }
        return head;
    }
};