/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/validate-stack-sequences/
 */

class Solution {
  public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        stack<int> s;
        int i = 0;
        int j = 0;
        int size = pushed.size();
        while (i < size) {
            s.emplace(pushed[i]);
            while (!s.empty() && s.top() == popped[j]) {
                s.pop();
                j++;
            }
            i++;
        }
        return s.empty();
    }
};