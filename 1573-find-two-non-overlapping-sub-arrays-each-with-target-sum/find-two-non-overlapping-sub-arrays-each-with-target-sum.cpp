class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> dp(n, INT_MAX);   // dp[i] = shortest valid subarray length ending at or before i
        int ans = INT_MAX;
        int left = 0, sum = 0;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            if (sum == target) {
                int len = right - left + 1;

                if (left > 0 && dp[left - 1] != INT_MAX) {
                    ans = min(ans, len + dp[left - 1]);
                }

                dp[right] = (right > 0) ? min(dp[right - 1], len) : len;
            } else {
                dp[right] = (right > 0) ? dp[right - 1] : INT_MAX;
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};