class Solution {
public:
  // Time Complexity: O(n)
  // Space Complexity: O(n)
  int calPoints(vector<string> &ops) {
    stack<int> st;
    int first = 0, second = 0;
    int sum = 0;
    for (const auto &op : ops) {
      if (op == "+") {
        auto [first, second] = getTopTwo(st);
        st.push(first + second);
      } else if (op == "D") {
        assert(!st.empty());
        st.push(st.top() * 2);
      } else if (op == "C") {
        assert(!st.empty());
        sum -= st.top();
        st.pop();
        continue;
      } else {
        st.push(stoi(op));
      }
      sum += st.top();
    }
    return sum;
  }

  pair<int, int> getTopTwo(stack<int> &st) {
    assert(!st.empty());
    int first = st.top();
    st.pop();
    assert(!st.empty());
    int second = st.top();
    st.push(first);
    return {first, second};
  }
};
