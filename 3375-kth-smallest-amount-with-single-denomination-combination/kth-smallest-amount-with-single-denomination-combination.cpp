class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        long long lo = 1, hi = 1e15;

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            long long count = 0;

            // count reachable amounts <= mid using inclusion-exclusion
            for (int mask = 1; mask < (1 << n); mask++) {
                long long curLcm = 1;
                int bits = __builtin_popcount(mask);
                bool overflow = false;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        long long g = __gcd(curLcm, (long long)coins[i]);
                        long long newLcm = curLcm / g * coins[i];
                        if (newLcm > mid) { overflow = true; break; }
                        curLcm = newLcm;
                    }
                }

                if (overflow) continue;

                long long term = mid / curLcm;
                count += (bits % 2 == 1) ? term : -term;
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