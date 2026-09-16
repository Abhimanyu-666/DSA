class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;
        // dp[j][i] = ways to form j segments using points 1..i
        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, 0));
        
        for (int i = 0; i <= n; i++) dp[0][i] = 1;  // 0 segments -> 1 way
        
        for (int j = 1; j <= k; j++) {
            long long runningSum = 0;
            for (int i = 1; i <= n; i++) {
                dp[j][i] = (dp[j][i - 1] + runningSum) % MOD;
                runningSum = (runningSum + dp[j - 1][i]) % MOD;
            }
        }
        
        return (int) dp[k][n];
    }
};