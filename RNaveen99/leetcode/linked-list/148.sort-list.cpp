/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/sort-list/
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
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *mid = getMid(head);
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        return merge(left, right);
    }
    ListNode *getMid(ListNode *head) {
        ListNode *tail = head;
        ListNode *prev = head;
        while (tail && tail->next) {
            prev = head;
            head = head->next;
            tail = tail->next->next;
        }
        prev->next = nullptr;
        return head;
    }
    ListNode *merge(ListNode *head1, ListNode *head2) {
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        while (head1 && head2) {
            if (head1->val <= head2->val) {
                tail->next = head1;
                head1 = head1->next;
            } else {
                tail->next = head2;
                head2 = head2->next;
            }
            tail = tail->next;
        }
        tail->next = head1 ? head1 : head2;
        return dummy->next;
    }
};