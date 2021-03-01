// @author: Himanshu
// @user: singalhimanshu
// Link: https://www.geeksforgeeks.org/implement-two-stacks-in-an-array/
#include <iostream>

using namespace std;

// Space efficient implementation
class TwoStack {
private:
  int top1;
  int top2;
  int *arr;
  int limit;

public:
  TwoStack(int limit)
      : top1(-1), top2(limit), arr(new int[limit]), limit(limit) {}
  ~TwoStack() { delete[] arr; }
  void push1(int val);
  void push2(int val);
  int topFirst();
  int topSecond();
  void pop1();
  void pop2();
  void print1();
  void print2();
  bool isFull();
  bool isEmpty1();
  bool isEmpty2();
};

void TwoStack::push1(int val) {
  if (isFull()) {
    cout << "Stack overflow\n";
    return;
  }
  arr[++top1] = val;
}

void TwoStack::push2(int val) {
  if (isFull()) {
    cout << "Stack overflow\n";
    return;
  }
  arr[--top2] = val;
}

int TwoStack::topFirst() {
  if (isEmpty1()) {
    cout << "Stack underflow\n";
    return -1;
  }
  return arr[top1];
}

int TwoStack::topSecond() {
  if (isEmpty2()) {
    cout << "Stack underflow\n";
    return -1;
  }
  return arr[top2];
}

void TwoStack::pop1() {
  if (isEmpty1()) {
    cout << "Stack underflow\n";
  }
  top1--;
}

void TwoStack::pop2() {
  if (isEmpty2()) {
    cout << "Stack underflow\n";
  }
  top2++;
}

void TwoStack::print1() {
  for (int i = top1; i >= 0; i--) {
    cout << arr[i] << ' ';
  }
  cout << '\n';
}

void TwoStack::print2() {
  for (int i = top2; i < limit; i++) {
    cout << arr[i] << ' ';
  }
  cout << '\n';
}

bool TwoStack::isFull() { return top1 == top2 - 1; }

bool TwoStack::isEmpty1() { return top1 == -1; }

bool TwoStack::isEmpty2() { return top2 == limit; }

int main() {
  TwoStack *two_stack = new TwoStack(5);
  two_stack->push1(1);
  two_stack->push1(2);
  two_stack->push2(3);
  two_stack->push2(4);
  two_stack->print1();
  two_stack->print2();
  delete (two_stack);
  return 0;
}