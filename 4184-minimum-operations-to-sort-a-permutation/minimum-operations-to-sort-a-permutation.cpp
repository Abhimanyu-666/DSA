class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int a = nums[0];

        bool isA = true, isB = true;
        for (int i = 0; i < n && (isA || isB); i++) {
            if (nums[i] != (i + a) % n) isA = false;
            if (nums[i] != ((a - i) % n + n) % n) isB = false;
        }
        if (!isA && !isB) return -1;

        int ans = INT_MAX;

        if (isA) {
            int viaRotate = (n - a) % n;
            int viaReverse = min((n - a) % n, a) + 2;
            ans = min(ans, min(viaRotate, viaReverse));
        }
        if (isB) {
            int d = (a + 1) % n;
            ans = min(ans, min(d, (n - d) % n) + 1);
        }
        return ans;
    }
};