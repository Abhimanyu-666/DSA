class Solution {
public:
    int smallestUniqueSubarray(vector<int>& a) {
        int n = a.size();
        vector<int> sa(n), rk(n), tmp(n), lcp(n + 1, 0);

        iota(sa.begin(), sa.end(), 0);
        for (int i = 0; i < n; i++) rk[i] = a[i];

        // suffix array by prefix doubling
        for (int k = 1;; k <<= 1) {
            auto cmp = [&](int x, int y) {
                if (rk[x] != rk[y]) return rk[x] < rk[y];
                int rx = x + k < n ? rk[x + k] : -1;
                int ry = y + k < n ? rk[y + k] : -1;
                return rx < ry;
            };
            sort(sa.begin(), sa.end(), cmp);
            tmp[sa[0]] = 0;
            for (int i = 1; i < n; i++)
                tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
            rk = tmp;
            if (rk[sa[n - 1]] == n - 1) break;
        }

        // Kasai: lcp[r] = LCP(suffix sa[r-1], suffix sa[r])
        int h = 0;
        for (int i = 0; i < n; i++) {
            if (rk[i] > 0) {
                int j = sa[rk[i] - 1];
                while (i + h < n && j + h < n && a[i + h] == a[j + h]) h++;
                lcp[rk[i]] = h;
                if (h > 0) h--;
            } else {
                h = 0;
            }
        }

        int ans = n;
        for (int r = 0; r < n; r++) {
            int left = r > 0 ? lcp[r] : 0;
            int right = r + 1 < n ? lcp[r + 1] : 0;
            int need = max(left, right) + 1;
            if (need <= n - sa[r]) ans = min(ans, need);
        }
        return ans;
    }
};