/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/beautiful-arrangement/
 */

class Solution {
    int count = 0;
    vector<int> numbers;

  public:
    int countArrangement(int n) {
        for (int i = 1; i <= n; i++) {
            numbers.emplace_back(i);
        }
        countArrangementUtil(0);
        return count;
    }

    void countArrangementUtil(int start) {
        if (start == numbers.size()) {
            count++;
        }
        for (int i = start; i < numbers.size(); i++) {
            swap(numbers[start], numbers[i]);
            if ((numbers[start] % (start + 1) == 0) || (start + 1) % numbers[start] == 0) {
                countArrangementUtil(start + 1);
            }
            swap(numbers[start], numbers[i]);
        }
    }
};