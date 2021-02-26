/**
 * Author: Naveen Rohilla
 * User: RNaveen99
 * Link: https://leetcode.com/problems/palindrome-linked-list/
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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head -> next == NULL) {
            return true;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* second_half_reverse = reverseList(slow);
        slow = head;
        fast = second_half_reverse;
        
        bool isPal = true;
        while (slow && fast) {
            if (slow -> val != fast -> val) {
                isPal = false;
                break;
            }
            slow = slow -> next;
            fast = fast -> next;
        }
        reverseList(second_half_reverse);
        return isPal;
        
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode = NULL;

        while (curr) {
            nextNode = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
};
