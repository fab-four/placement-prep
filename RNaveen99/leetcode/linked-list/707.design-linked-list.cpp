/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/design-linked-list/
 */

class Node {
  public:
    int val;
    Node *next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};
class MyLinkedList {
  private:
    Node *head;
    Node *tail;
    int size;

  public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= size)
            return -1;
        int i = 0;
        Node *temp = head;
        while (i != index) {
            i++;
            temp = temp->next;
        }
        if (i != index || !temp)
            return -1;
        return temp->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node
     * will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *temp = new Node(val);
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            temp->next = head;
            head = temp;
        }
        size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *temp = new Node(val);
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of
     * linked list, the node will be appended to the end of linked list. If index is greater than the length,
     * the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size)
            ;
        else if (index == 0) {
            addAtHead(val);
        } else if (index == size) {
            addAtTail(val);
        } else {
            int i = 0;
            Node *temp = head;
            while (i != index - 1) {
                temp = temp->next;
                i++;
            }
            Node *node = new Node(val);
            node->next = temp->next;
            temp->next = node;
            size++;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < size) {
            int i = 0;
            Node *temp = head;
            Node *prev = NULL;
            while (i != index) {
                i++;
                prev = temp;
                temp = temp->next;
            }
            if (prev == NULL) {
                head = head->next;
                if (head == NULL) {
                    tail = NULL;
                }
            } else if (temp == tail) {
                prev->next = NULL;
                tail = prev;
            } else {
                prev->next = temp->next;
            }
            size--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */