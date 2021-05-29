/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/insertion-sort-list/
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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *itr = head->next;
        ListNode *itrPrev = head;
        ListNode *prev;
        while (itr) {
            prev = dummy;
            head = dummy->next;
            while (itr->val >= head->val && head != itr) {
                head = head->next;
                prev = prev->next;
            }
            if (head == itr) {
                itrPrev = itr;
                itr = itr->next;
            } else {
                ListNode *nextNode = itr->next;
                itrPrev->next = nextNode;

                itr->next = head;
                prev->next = itr;

                itr = nextNode;
            }
        }
        return dummy->next;
    }
};