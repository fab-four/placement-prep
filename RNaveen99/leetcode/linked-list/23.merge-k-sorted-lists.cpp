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
// T : O(N * log(k))
// S : O(1)
class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty())
            return NULL;
        int len = lists.size();
        while (len > 1) {
            for (int i = 0; i < len / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
            }
            len = (len + 1) / 2;
        }

        return lists.front();
    }
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
        }
        tail->next = l1 ? l1 : l2;
        return dummy->next;
    }
};