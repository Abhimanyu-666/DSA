class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        auto rangeSum = [&](int l, int r) {
            return prefix[r + 1] - prefix[l];
        };

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                int best = 0;

                for (int k = i; k < j; k++) {
                    int leftSum = rangeSum(i, k);
                    int rightSum = rangeSum(k + 1, j);

                    if (leftSum < rightSum) {
                        best = max(best, dp[i][k] + leftSum);
                    } else if (leftSum > rightSum) {
                        best = max(best, dp[k + 1][j] + rightSum);
                    } else {
                        best = max(best, max(dp[i][k], dp[k + 1][j]) + leftSum);
                    }
                }

                dp[i][j] = best;
            }
        }

        return dp[0][n - 1];
    }
};