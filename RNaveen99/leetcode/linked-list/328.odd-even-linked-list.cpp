/**
 * Author: Naveen Rohilla
 * User:   RNaveen99
 * Link:   https://leetcode.com/problems/odd-even-linked-list/
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddList = new ListNode(0);
        ListNode* oddPointer = oddList;
        ListNode* evenList = new ListNode(0);
        ListNode* evenPointer = evenList;
        
        int index = 1;
        while (head) {
            if (index & 1) {
                oddPointer -> next = head;
                oddPointer = oddPointer -> next;
            } else {
                evenPointer -> next = head;
                evenPointer = evenPointer -> next;
            }
            head = head -> next;
            index = index + 1;
        }
        evenPointer -> next = NULL;
        oddPointer -> next = evenList -> next;
        return oddList -> next;
    }
};
