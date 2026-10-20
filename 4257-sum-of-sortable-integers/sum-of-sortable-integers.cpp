class Solution {
public:
    long long sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k) continue;

            bool ok = true;
            int prevMax = 0;  // nums[i] >= 1, so 0 works as -infinity

            for (int s = 0; s < n && ok; s += k) {
                int cnt = 0, mn = INT_MAX, mx = 0;
                for (int j = 0; j < k; j++) {
                    int cur = nums[s + j];
                    int nxt = nums[s + (j + 1) % k];
                    if (cur > nxt) cnt++;
                    mn = min(mn, cur);
                    mx = max(mx, cur);
                }
                if (cnt > 1 || mn < prevMax) ok = false;
                prevMax = mx;
            }

            if (ok) ans += k;
        }
        return ans;
    }
};