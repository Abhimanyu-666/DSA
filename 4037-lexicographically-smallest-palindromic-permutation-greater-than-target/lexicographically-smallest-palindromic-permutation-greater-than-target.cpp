class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        // Palindrome feasibility check
        int oddCount = 0, oddChar = -1;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) { oddCount++; oddChar = i; }
        }
        if ((n % 2 == 0 && oddCount != 0) || (n % 2 == 1 && oddCount != 1)) return "";

        int m = n / 2;
        vector<int> H(26, 0);
        for (int i = 0; i < 26; i++) H[i] = cnt[i] / 2;
        char middle = (n % 2 == 1) ? char('a' + oddChar) : 0;

        // Forward pass: find max feasible prefix-match length M0
        vector<int> pool = H;
        int M0 = m;
        for (int i = 0; i < m; i++) {
            int c = target[i] - 'a';
            if (pool[c] <= 0) { M0 = i; break; }
            pool[c]--;
        }

        // Try the full-match case first (best possible if valid)
        if (M0 == m) {
            string firstHalf = target.substr(0, m);
            string second = firstHalf;
            reverse(second.begin(), second.end());
            string candidate = firstHalf + (n % 2 ? string(1, middle) : "") + second;
            if (candidate > target) return candidate;
            if (m > 0) pool[target[m - 1] - 'a']++; // undo last consumption
        }

        int k = min(M0, m - 1);
        for (; k >= 0; k--) {
            int tc = target[k] - 'a';
            int chosen = -1;
            for (int c = tc + 1; c < 26; c++) {
                if (pool[c] > 0) { chosen = c; break; }
            }

            if (chosen != -1) {
                vector<int> p = pool;
                p[chosen]--;

                string firstHalf = target.substr(0, k);
                firstHalf += char('a' + chosen);
                for (int c = 0; c < 26; c++) {
                    firstHalf.append(p[c], char('a' + c)); // fill ascending
                }

                string second = firstHalf;
                reverse(second.begin(), second.end());
                return firstHalf + (n % 2 ? string(1, middle) : "") + second;
            }

            if (k > 0) pool[target[k - 1] - 'a']++; // undo one more step
        }

        return "";
    }
};