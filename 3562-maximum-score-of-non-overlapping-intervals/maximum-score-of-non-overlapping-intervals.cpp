class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<array<long long,4>> arr(n); // {l, r, w, originalIndex}
        for (int i = 0; i < n; i++)
            arr[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};

        sort(arr.begin(), arr.end(), [](auto& a, auto& b){ return a[1] < b[1]; });

        vector<long long> rVals(n);
        for (int i = 0; i < n; i++) rVals[i] = arr[i][1];

        using State = pair<long long, vector<int>>;
        vector<vector<State>> dp(n+1, vector<State>(5, {0, {}}));

        auto better = [](const State& a, const State& b) -> State {
            if (a.first != b.first) return a.first > b.first ? a : b;
            return a.second < b.second ? a : b;
        };

        for (int i = 1; i <= n; i++) {
            long long l_i = arr[i-1][0], w_i = arr[i-1][2];
            int idx_i = (int)arr[i-1][3];

            int p = lower_bound(rVals.begin(), rVals.end(), l_i) - rVals.begin();
            p = min(p, i-1);

            dp[i][0] = {0, {}};
            for (int k = 1; k <= 4; k++) {
                State skip = dp[i-1][k];

                State base = dp[p][k-1];
                vector<int> idxs = base.second;
                idxs.push_back(idx_i);
                sort(idxs.begin(), idxs.end());
                State take = {base.first + w_i, idxs};

                dp[i][k] = better(skip, take);
            }
        }
        return dp[n][4].second;
    }
};