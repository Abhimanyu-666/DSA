class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int a = nums[0];

        // type A: nums[i] = (a + i) mod n, so each step is +1 (wrapping n-1 -> 0)
        // type B: nums[i] = (a - i) mod n, so each step is -1 (wrapping 0 -> n-1)
        bool isA = true, isB = true;
        for (int i = 1; i < n && (isA || isB); i++) {
            int prev = nums[i - 1], cur = nums[i];
            if (cur != (prev + 1 == n ? 0 : prev + 1)) isA = false;
            if (cur != (prev == 0 ? n - 1 : prev - 1)) isB = false;
        }
        if (!isA && !isB) return -1;

        int ans = INT_MAX;
        if (isA) {
            int rot = (n - a) % n;
            ans = min(ans, min(rot, min(rot, a) + 2));
        }
        if (isB) {
            int d = (a + 1) % n;
            ans = min(ans, min(d, (n - d) % n) + 1);
        }
        return ans;
    }
};