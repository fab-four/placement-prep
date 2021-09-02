/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/search-suggestions-system/
 */

class Solution {
  public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord) {
        sort(products.begin(), products.end());
        int size = searchWord.size();
        int left = 0;
        int right = products.size() - 1;
        vector<vector<string>> result(size);

        for (int index = 0; index < size; index++) {
            while (left <= right &&
                   (products[left].size() <= index || products[left][index] != searchWord[index])) {
                left++;
            }
            while (left <= right &&
                   (products[right].size() <= index || products[right][index] != searchWord[index])) {
                right--;
            }
            for (int j = left; j <= right && j < left + 3; j++) {
                result[index].emplace_back(products[j]);
            }
        }
        return result;
    }
};