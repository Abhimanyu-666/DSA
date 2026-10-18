class Solution {
    static const long long MOD = 1e9 + 7;

    long long power(long long b, long long e) {
        long long r = 1;
        b %= MOD;
        while (e) {
            if (e & 1) r = r * b % MOD;
            b = b * b % MOD;
            e >>= 1;
        }
        return r;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        // build BST over indices: node i = nums[i]
        vector<int> lc(n, -1), rc(n, -1);
        for (int i = 1; i < n; i++) {
            int cur = 0;
            while (true) {
                if (nums[i] < nums[cur]) {
                    if (lc[cur] == -1) { lc[cur] = i; break; }
                    cur = lc[cur];
                } else {
                    if (rc[cur] == -1) { rc[cur] = i; break; }
                    cur = rc[cur];
                }
            }
        }

        // nodes are inserted after their parent, so index order is a
        // valid top-down order. Process in reverse for subtree sizes.
        vector<int> sz(n, 1);
        for (int i = n - 1; i >= 0; i--) {
            if (lc[i] != -1) sz[i] += sz[lc[i]];
            if (rc[i] != -1) sz[i] += sz[rc[i]];
        }

        // n! / product of sizes
        long long fact = 1, denom = 1;
        for (int i = 1; i <= n; i++) fact = fact * i % MOD;
        for (int i = 0; i < n; i++) denom = denom * sz[i] % MOD;

        long long total = fact * power(denom, MOD - 2) % MOD;
        return (total - 1 + MOD) % MOD;
    }
};