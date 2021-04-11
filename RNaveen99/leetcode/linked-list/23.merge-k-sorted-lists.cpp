/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/merge-k-sorted-lists/
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
struct comparator {
    int operator()(ListNode *l1, ListNode *l2) { return l1->val > l2->val; }
};
class myComparator {
  public:
    int operator()(ListNode *l1, ListNode *l2) { return l1->val > l2->val; }
};
class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, comparator> pq;

        for (ListNode *list : lists) {
            if (list) {
                pq.emplace(list);
            }
        }
        ListNode *mergedList = new ListNode(-1);
        ListNode *tail = mergedList;

        while (!pq.empty()) {
            ListNode *temp = pq.top();
            pq.pop();

            tail->next = temp;
            tail = tail->next;

            if (tail->next) {
                pq.push(tail->next);
            }
        }
        return mergedList->next;
    }
};