class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long even = 1, odd = 0;   // empty prefix (sum 0) is even
        int parity = 0;
        long long ans = 0;

        for (int x : arr) {
            parity ^= (x & 1);
            if (parity) {              // current prefix is odd
                ans += even;           // pair with every earlier even prefix
                odd++;
            } else {                   // current prefix is even
                ans += odd;            // pair with every earlier odd prefix
                even++;
            }
            ans %= MOD;
        }
        return ans;
    }
};