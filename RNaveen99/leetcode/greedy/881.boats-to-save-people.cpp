/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/boats-to-save-people/
 */

// greedy, 2-pointers
class Solution {
  public:
    int numRescueBoats(vector<int> &people, int limit) {
        sort(people.begin(), people.end());
        int boats = 0;
        int i = 0;
        int j = people.size() - 1;
        while (i <= j) {
            int sum = people[i] + people[j];
            if (sum <= limit) {
                boats++;
                i++;
                j--;
            } else {
                boats++;
                j--;
            }
        }
        return boats;
    }
};