class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            a[i] = 1LL * nums[i] * nums[i];

        sort(a.begin(), a.end());

        int minus = n / 2;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (i < minus) ans -= a[i];
            else ans += a[i];
        }
        return ans;
    }
};