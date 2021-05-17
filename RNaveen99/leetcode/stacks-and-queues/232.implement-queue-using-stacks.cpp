/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/implement-queue-using-stacks/
 */

class MyQueue {
    stack<int> s;
    stack<int> aux;
    void _transfer() {
        while (!s.empty()) {
            aux.push(s.top());
            s.pop();
        }
    }

  public:
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) { s.push(x); }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (aux.empty()) {
            _transfer();
        }
        int ele = aux.top();
        aux.pop();
        return ele;
    }

    /** Get the front element. */
    int peek() {
        if (aux.empty()) {
            _transfer();
        }
        int ele = aux.top();
        return ele;
    }

    /** Returns whether the queue is empty. */
    bool empty() { return s.empty() && aux.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */