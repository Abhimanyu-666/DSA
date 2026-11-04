class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> cost(n - x + 1);

        multiset<int> lo, hi;
        long long sl = 0, sh = 0;

        auto add = [&](int v) {
            if (lo.empty() || v <= *lo.rbegin()) { lo.insert(v); sl += v; }
            else { hi.insert(v); sh += v; }
        };
        auto rem = [&](int v) {
            auto it = lo.find(v);
            if (it != lo.end()) { lo.erase(it); sl -= v; }
            else { hi.erase(hi.find(v)); sh -= v; }
        };
        auto balance = [&]() {
            size_t want = (x + 1) / 2;
            while (lo.size() > want) {
                auto it = prev(lo.end());
                hi.insert(*it); sh += *it; sl -= *it;
                lo.erase(it);
            }
            while (lo.size() < want && !hi.empty()) {
                auto it = hi.begin();
                lo.insert(*it); sl += *it; sh -= *it;
                hi.erase(it);
            }
        };

        for (int i = 0; i < n; i++) {
            add(nums[i]);
            if (i >= x) rem(nums[i - x]);
            balance();
            if (i >= x - 1) {
                long long med = *lo.rbegin();
                cost[i - x + 1] = med * (long long)lo.size() - sl
                                + sh - med * (long long)hi.size();
            }
        }

        const long long INF = LLONG_MAX / 4;
        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, INF));
        for (int i = 0; i <= n; i++) dp[0][i] = 0;

        for (int j = 1; j <= k; j++) {
            for (int i = 1; i <= n; i++) {
                dp[j][i] = dp[j][i - 1];
                if (i >= x && dp[j - 1][i - x] < INF)
                    dp[j][i] = min(dp[j][i], dp[j - 1][i - x] + cost[i - x]);
            }
        }
        return dp[k][n];
    }
};