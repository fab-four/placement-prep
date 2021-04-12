/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/reorder-list/
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
    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *next = nullptr;

        while (curr) {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode *mergeList(ListNode *A, ListNode *B) {
        ListNode *C = new ListNode(0);
        ListNode *tail = C;
        int i = 1;
        while (A && B) {
            if (i) {
                tail->next = A;
                A = A->next;
            } else {
                tail->next = B;
                B = B->next;
            }
            i ^= 1;
            tail = tail->next;
        }
        tail->next = A ? A : B;
        return C->next;
    }
    void reorderList(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (prev) {
            prev->next = nullptr;
            ListNode *B = reverseList(slow);
            head = mergeList(head, B);
        }
    }
};