class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        auto digitSum = [](int x) {
            int s = 0;
            while (x) { s += x % 10; x /= 10; }
            return s;
        };

        // (digitSum, value, originalIndex)
        vector<array<int, 3>> a(n);
        for (int i = 0; i < n; i++)
            a[i] = {digitSum(nums[i]), nums[i], i};

        sort(a.begin(), a.end());

        // a[pos][2] is the original index that belongs at sorted position pos
        vector<bool> vis(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || a[i][2] == i) continue;

            int len = 0;
            int j = i;
            while (!vis[j]) {
                vis[j] = true;
                j = a[j][2];
                len++;
            }
            swaps += len - 1;
        }

        return swaps;
    }
};