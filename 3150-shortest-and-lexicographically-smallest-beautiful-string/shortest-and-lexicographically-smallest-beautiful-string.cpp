class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        vector<int> ones;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') ones.push_back(i);
        }

        int m = ones.size();
        if (m < k) return "";

        int minLen = INT_MAX;
        string result = "";

        for (int i = 0; i + k - 1 < m; i++) {
            int start = ones[i];
            int end = ones[i + k - 1];
            int len = end - start + 1;
            string candidate = s.substr(start, len);

            if (len < minLen || (len == minLen && candidate < result)) {
                minLen = len;
                result = candidate;
            }
        }

        return result;
    }
};