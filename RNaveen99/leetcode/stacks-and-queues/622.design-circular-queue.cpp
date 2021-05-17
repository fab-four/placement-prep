/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/design-circular-queue/
 */

class MyCircularQueue {
    vector<int> q;
    int size;
    int head = -1;
    int tail = -1;

  public:
    MyCircularQueue(int k) {
        size = k;
        q = vector<int>(size);
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            head = tail = 0;
        } else {
            tail = (tail + 1) % size;
        }
        q[tail] = value;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        if (head == tail) {
            head = tail = -1;
        } else {
            head = (head + 1) % size;
        }
        return true;
    }

    int Front() {
        if (isEmpty())
            return -1;
        return q[head];
    }

    int Rear() {
        if (isEmpty())
            return -1;

        return q[tail];
    }

    bool isEmpty() { return head == -1; }

    bool isFull() { return (tail + 1) % size == head; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */