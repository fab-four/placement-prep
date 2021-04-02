// @author: Himanshu
// @user: singalhimanshu

#include <iostream>
#include <vector>

using namespace std;

class Heap {
public:
  Heap(size_t min_heap_size = 10, bool is_min_min_heap = true)
      : m_is_min_min_heap(is_min_min_heap) {
    m_min_heap_size = min_heap_size;
    m_arr.reserve(m_min_heap_size);
  }
  void push(int data);
  int top();
  void pop();
  void print();
  void heapify(vector<int> &arr, size_t idx, size_t cur_heap_size);
  void make_heap(vector<int> &arr);

private:
  vector<int> m_arr;
  size_t m_min_heap_size;
  bool m_is_min_min_heap;
  bool compare(int child, int parent) {
    return m_is_min_min_heap ? (child < parent) : (child > parent);
  }
  bool isEmpty() { return m_arr.size() == 0; }
};

void Heap::push(int data) {
  m_arr.emplace_back(data);
  int cur_idx = m_arr.size() - 1;
  int parent_idx = cur_idx / 2;
  while (cur_idx >= 0 && compare(m_arr[cur_idx], m_arr[parent_idx])) {
    swap(m_arr[cur_idx], m_arr[parent_idx]);
    cur_idx = parent_idx;
    parent_idx /= 2;
  }
}

int Heap::top() {
  if (isEmpty()) {
    return -1;
  }
  return m_arr[0];
}
void Heap::pop() {
  if (isEmpty()) {
    return;
  }
  size_t last_idx = m_arr.size() - 1;
  size_t first_idx = 0;
  swap(m_arr[first_idx], m_arr[last_idx]);
  m_arr.pop_back();
  heapify(m_arr, first_idx, m_arr.size());
}

void Heap::heapify(vector<int> &arr, size_t idx, size_t cur_heap_size) {
  size_t left_child_idx = idx * 2 + 1;
  size_t right_child_idx = left_child_idx + 1;
  size_t last_idx = arr.size() - 1;
  size_t min_idx = idx;
  if (left_child_idx <= last_idx &&
      compare(arr[left_child_idx], arr[min_idx])) {
    min_idx = left_child_idx;
  }
  if (right_child_idx <= last_idx &&
      compare(arr[right_child_idx], arr[min_idx])) {
    min_idx = right_child_idx;
  }
  if (min_idx != idx) {
    swap(arr[idx], arr[min_idx]);
    heapify(arr, min_idx, m_arr.size());
  }
}

void Heap::print() {
  for (const auto &it : m_arr) {
    cout << it << ' ';
  }
  cout << '\n';
}

void Heap::make_heap(vector<int> &arr) {
  for (ssize_t i = arr.size() / 2; i >= 0; i--) {
    heapify(arr, i, arr.size());
  }
}

void printArray(const vector<int> &arr) {
  for (const auto &it : arr) {
    cout << it << ' ';
  }
  cout << '\n';
}

void heapsort(vector<int> &arr) {
  Heap heap(arr.size());
  heap.make_heap(arr);
  ssize_t n = arr.size();
  while (n > 0) {
    swap(arr[0], arr[n - 1]);
    n--;
    heap.heapify(arr, 0, n);
  }
}

int main() {
  Heap min_heap(10);
  min_heap.push(10);
  min_heap.push(1);
  min_heap.push(17);
  min_heap.push(3);
  min_heap.push(2);
  min_heap.push(-2);
  min_heap.print();
  auto top_ele = min_heap.top();
  cout << top_ele << '\n';
  min_heap.pop();
  min_heap.push(1);
  min_heap.print();
  top_ele = min_heap.top();
  cout << top_ele << '\n';
  min_heap.print();
  vector<int> arr{10, 1, 9, 2, 10};
  cout << "Heapsort: \n";
  heapsort(arr);
  printArray(arr);
  return 0;
}
