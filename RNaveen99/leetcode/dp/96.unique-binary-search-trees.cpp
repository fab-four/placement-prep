/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/unique-binary-search-trees/
 */

// 1 <= i <= n

// F(i, n): the number of unique BST, where the number i is the root.
// Trees(n): the number of unique BST with n nodes.

// Notice that when we select i as a root, we have i - 1 nodes which can be used to form a left
// subtree; similarly we have n - i nodes to form a right subtree.

// F(i, n) = Trees(i - 1) * Trees(n - i)
// Trees(n) = sum(F(i, n)) for 1 <= i <= n
// Trees(0) = Trees(1) = 1

class Solution {
    vector<int> cache;

  public:
    int numTrees(int n) {
        cache = vector<int>(n + 1, 0);
        cache[0] = cache[1] = 1;
        return numTreesUtil(n);
    }

    int numTreesUtil(int n) {
        if (cache[n] > 0)
            return cache[n];

        int total = 0;
        for (int i = 0; i < n; i++) {
            int numOfLeftNodes = i;
            int numOfRightNodes = n - i - 1;

            int numOfLeftSubtrees = numTreesUtil(numOfLeftNodes);
            int numOfRightSubtrees = numTreesUtil(numOfRightNodes);
            total += numOfLeftSubtrees * numOfRightSubtrees;
        }
        cache[n] = total;
        return total;
    }
};

// G(n) = G(0) * G(n-1) + G(1) * G(n-2) + … + G(n-1) * G(0)
class Solution {
  public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int nodes = 2; nodes <= n; nodes++) {
            for (int j = 1; j <= nodes; j++) {
                dp[nodes] += dp[j - 1] * dp[nodes - j];
            }
        }
        return dp[n];
    }
};