class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0, count = 0;
        int bestLen = INT_MAX, bestStart = -1;

        for (int right = 0; right < n; ++right) {
            if (s[right] == '1') ++count;

            while (count == k) {
                while (s[left] == '0') ++left;   // window must start at a '1'

                int len = right - left + 1;
                if (len < bestLen ||
                    (len == bestLen && s.compare(left, len, s, bestStart, len) < 0)) {
                    bestLen = len;
                    bestStart = left;
                }

                --count;   // drop the leading '1', look for the next window
                ++left;
            }
        }

        return bestStart == -1 ? "" : s.substr(bestStart, bestLen);
    }
};