class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        // Tighter upper bound: using only the smallest coin, the kth multiple
        // is always reachable, so the true answer can never exceed this.
        long long minCoin = *min_element(coins.begin(), coins.end());
        long long hi = minCoin * k;
        long long lo = 1;

        // Precompute LCM (and its inclusion-exclusion sign) for every non-empty
        // subset ONCE, outside the binary search — this LCM never depends on
        // the binary search's current guess, only on `coins` itself.
        vector<long long> subsetLcm;
        vector<int> subsetSign;

        for (int mask = 1; mask < (1 << n); mask++) {
            long long curLcm = 1;
            bool overflow = false;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    long long g = __gcd(curLcm, (long long)coins[i]);
                    long long newLcm = curLcm / g * coins[i];
                    if (newLcm > hi) { overflow = true; break; } // never useful beyond hi
                    curLcm = newLcm;
                }
            }

            if (overflow) continue; // skip storing subsets that can never contribute

            subsetLcm.push_back(curLcm);
            subsetSign.push_back(__builtin_popcount(mask) % 2 == 1 ? 1 : -1);
        }

        // Binary search now does O(1) work per subset instead of O(n)
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            long long count = 0;

            for (int idx = 0; idx < subsetLcm.size(); idx++) {
                count += subsetSign[idx] * (mid / subsetLcm[idx]);
            }

            if (count >= k) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};