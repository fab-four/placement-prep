/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/angle-between-hands-of-a-clock/
 */

// For Hour Hand
// In 12 hrs = 360 degree
// => 1hr = 30 degree
// => 60 min = 30 degree
// => 1 min = (1 / 2) degree

// For minute hand
// In 60 min = 360 degree
// => 1 min = 6 degree

class Solution {
  public:
    double angleClock(int hour, int minutes) {
        int distanceByHr = hour * 30;
        double distanceByHrAndMinute = distanceByHr + (double)minutes / 2;
        int distanceByMinute = minutes * 6;

        double diff = abs(distanceByHrAndMinute - distanceByMinute);

        return min(diff, 360 - diff);
    }
};