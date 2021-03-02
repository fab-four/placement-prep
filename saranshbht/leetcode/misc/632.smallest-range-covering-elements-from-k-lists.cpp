/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   :
 * https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
 */

class Solution {
public:
  vector<int> smallestRange(vector<vector<int>> &nums) {
    struct Node {
      int value;
      int row;
      int col;

      Node(int _value, int _row, int _col)
          : value(_value), row(_row), col(_col) {}
    };

    struct compare {
      bool operator()(Node a, Node b) { return a.value > b.value; }
    };
    int int_max = numeric_limits<int>::max();
    int int_min = numeric_limits<int>::min();

    int minm = int_max, maxm = int_min, range = int_max;
    priority_queue<Node, vector<Node>, compare> q;

    for (int i = 0; i < nums.size(); i++) {
      maxm = max(maxm, nums[i][0]);
      Node node(nums[i][0], i, 0);
      q.push(node);
    }

    int range_minm = int_max, range_maxm = int_min;

    while (true) {
      Node node = q.top();
      q.pop();

      minm = node.value;
      if (maxm - minm < range) {
        range_minm = minm;
        range_maxm = maxm;
        range = maxm - minm;
      }

      if (node.col + 1 == nums[node.row].size())
        break;
      Node next(nums[node.row][node.col + 1], node.row, node.col + 1);
      q.push(next);
      maxm = max(maxm, next.value);
    }

    return {range_minm, range_maxm};
  }
};