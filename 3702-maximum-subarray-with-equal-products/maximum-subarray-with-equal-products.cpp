class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long prod = 1, g = 0, l = 1;
            for (int j = i; j < n; j++) {
                prod *= nums[j];
                g = __gcd(g, (long long)nums[j]);
                l = l / __gcd(l, (long long)nums[j]) * nums[j];

                if (prod > 25200) break;   // can never match lcm * gcd again

                if (prod == l * g) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};