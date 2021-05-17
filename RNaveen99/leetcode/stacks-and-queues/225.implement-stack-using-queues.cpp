/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/implement-stack-using-queues/
 */
class MyStack {
    queue<int> q;

  public:
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x) {
        int size = q.size();
        q.emplace(x);
        while (size--) {
            q.emplace(q.front());
            q.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ele = q.front();
        q.pop();
        return ele;
    }

    /** Get the top element. */
    int top() {
        int ele = q.front();
        return ele;
    }

    /** Returns whether the stack is empty. */
    bool empty() { return q.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

class MyStack {
    queue<int> q;

  public:
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x) {
        queue<int> q2;
        q2.emplace(x);
        while (!q.empty()) {
            q2.emplace(q.front());
            q.pop();
        }
        q = q2;
        q2 = queue<int>();
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ele = q.front();
        q.pop();
        return ele;
    }

    /** Get the top element. */
    int top() {
        int ele = q.front();
        return ele;
    }

    /** Returns whether the stack is empty. */
    bool empty() { return q.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */