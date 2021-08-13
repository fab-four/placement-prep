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
  // Time Complexity: O(n)
  // Space Complexity: O(n)
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr && l2 == nullptr) {
      return nullptr;
    }
    stack<int> s1, s2;
    ListNode *cur1 = l1, *cur2 = l2;
    while (cur1) {
      s1.push(cur1->val);
      cur1 = cur1->next;
    }
    while (cur2) {
      s2.push(cur2->val);
      cur2 = cur2->next;
    }
    int carry = 0;
    ListNode *dummy = new ListNode(-1);
    ListNode *cur = dummy;
    while (!s1.empty() || !s2.empty()) {
      int first = 0;
      if (!s1.empty()) {
        first += s1.top();
        s1.pop();
      }
      int second = 0;
      if (!s2.empty()) {
        second += s2.top();
        s2.pop();
      }
      int sum = first + second + carry;
      carry = sum / 10;
      sum %= 10;
      cur->next = new ListNode(sum);
      cur = cur->next;
    }
    if (carry) {
      cur->next = new ListNode(carry);
    }
    ListNode *res = revList(dummy->next);
    delete dummy;
    return res;
  }

  ListNode *revList(ListNode *root) {
    if (root == nullptr) {
      return nullptr;
    }
    ListNode *prev = nullptr, *cur = root, *next = nullptr;
    while (cur) {
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    return prev;
  }
};
