/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/partition-list/
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
    ListNode *partition(ListNode *head, int x) {
        ListNode *head1 = new ListNode(0);
        ListNode *tail1 = head1;

        ListNode *head2 = new ListNode(0);
        ListNode *tail2 = head2;

        while (head) {
            if (head->val < x) {
                tail1->next = head;
                tail1 = tail1->next;
            } else {
                tail2->next = head;
                tail2 = tail2->next;
            }
            head = head->next;
        }
        tail1->next = head2->next;
        tail2->next = nullptr;

        return head1->next;
    }
};