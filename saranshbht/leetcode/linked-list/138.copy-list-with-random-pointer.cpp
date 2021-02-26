/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/copy-list-with-random-pointer/
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
  Node *copyRandomList(Node *head) {
    if (!head)
      return head;

    Node *current = head;
    while (current) {
      Node *node = new Node(current->val);
      node->next = current->next;
      current->next = node;
      current = node->next;
    }

    current = head;
    while (current) {
      current->next->random = current->random ? current->random->next : NULL;
      current = current->next->next;
    }

    current = head;
    Node *newHead = head->next;
    Node *newCurrent = head->next;
    while (current) {
      current->next = newCurrent->next;
      current = current->next;

      if (current) {
        newCurrent->next = current->next;
        newCurrent = newCurrent->next;
      }
    }

    return newHead;
  }
};