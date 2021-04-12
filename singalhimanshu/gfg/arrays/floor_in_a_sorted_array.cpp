// @author: Himanshu
// @user: singalhimanshu
// Link:
// https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1

typedef long long ll;
class Solution {
public:
  // Function to find floor of x
  // n: size of vector
  // x: element whose floor is to find
  ll findFloor(vector<long long> v, long long n, long long x) {
    ll low = 0, high = n - 1;
    ll ans = -1;
    while (low <= high) {
      ll mid = (low + high) / 2;
      if (v[mid] <= x) {
        ans = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return ans;
  }
};
