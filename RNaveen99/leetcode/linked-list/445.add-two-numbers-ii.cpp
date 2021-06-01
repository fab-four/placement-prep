/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/add-two-numbers-ii/
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        stack<ListNode *> s1;
        while (l1) {
            s1.push(l1);
            l1 = l1->next;
        }
        stack<ListNode *> s2;
        while (l2) {
            s2.push(l2);
            l2 = l2->next;
        }
        ListNode *dummy = nullptr;
        int carry = 0;
        while (!s1.empty() || !s2.empty() || carry) {
            int sum = (!s1.empty() ? s1.top()->val : 0) + (!s2.empty() ? s2.top()->val : 0) + carry;
            carry = sum / 10;
            dummy = new ListNode(sum % 10, dummy);
            if (!s1.empty())
                s1.pop();
            if (!s2.empty())
                s2.pop();
        }
        return dummy;
    }
};