class Solution {
public:
    long long maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<long long> v(n, 1);
        int pm = INT_MAX;
        for (int i = 0; i < n; i++) {
            pm = min(pm, items[i][1]);
            for (int j = 0; j < n; j++)
                if (i != j && items[j][0] % items[i][0] == 0) v[i]++;
        }

        vector<long long> dp(budget + 1, 0);   // dp[b]: best value with cost <= b
        for (int i = 0; i < n; i++) {
            int p = items[i][1];
            for (int b = budget; b >= p; b--)
                dp[b] = max(dp[b], dp[b - p] + v[i]);
        }

        long long ans = 0;
        for (int b = 0; b <= budget; b++)
            ans = max(ans, dp[b] + (budget - b) / pm);
        return ans;
    }
};