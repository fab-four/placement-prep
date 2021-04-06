// @author: Himanshu
// @user: singalhimanshu
// Link: https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int nums[], int lo, int hi, int k) {
        int rand_pivot_idx = lo + rand() % (hi - lo + 1);
        int pivot_idx = getPivotIdx(nums, rand_pivot_idx, lo, hi);
        if (pivot_idx == k - 1) {
            return nums[pivot_idx];
        }
        if (pivot_idx < k - 1) {
            return kthSmallest(nums, pivot_idx + 1, hi, k);
        }
        return kthSmallest(nums, lo, pivot_idx - 1, k);
    }

    int getPivotIdx(int nums[], int rand_pivot_idx, int lo, int hi) {
        swap(nums[hi], nums[rand_pivot_idx]);
        int pivot = nums[hi];
        int i = lo, j = lo;
        while (i <= hi) {
          if (nums[i] <= pivot) {
            swap(nums[i], nums[j]);
            i++;
            j++;
            continue;
          }
          i++;
        }
        return j - 1;
    }
};
