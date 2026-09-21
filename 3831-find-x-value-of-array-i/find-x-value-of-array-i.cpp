class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> newDp(k, 0);

            for (int v = 0; v < k; v++) {
                if (dp[v] > 0) {
                    // cast to long long BEFORE multiplying
                    long long idx = ((long long) v * num) % k;
                    newDp[idx] += dp[v];
                }
            }
            newDp[num % k] += 1;

            for (int v = 0; v < k; v++) {
                result[v] += newDp[v];
            }

            dp = newDp;
        }

        return result;
    }
};