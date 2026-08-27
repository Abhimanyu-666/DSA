class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        int best = -1;
        vector<int> cur = cnt; // running count as we consume target's prefix

        for (int i = 0; i < n; i++) {
            int t = target[i] - 'a';

            // is there something strictly greater available right now?
            bool found = false;
            for (int c = t + 1; c < 26; c++) {
                if (cur[c] > 0) { found = true; break; }
            }
            if (found) best = i;

            // try to extend the exact-match prefix
            if (cur[t] > 0) cur[t]--;
            else break; // can't match further, stop scanning
        }

        if (best == -1) return "";

        // Reconstruct the answer using the ORIGINAL counts
        vector<int> rem = cnt;
        string ans = target.substr(0, best); // prefix equals target[0..best-1]
        for (int k = 0; k < best; k++) rem[target[k] - 'a']--;

        int t = target[best] - 'a';
        int pick = -1;
        for (int c = t + 1; c < 26; c++) {
            if (rem[c] > 0) { pick = c; break; }
        }
        ans += char('a' + pick);
        rem[pick]--;

        for (int c = 0; c < 26; c++)
            ans += string(rem[c], char('a' + c)); // append remaining, sorted ascending

        return ans;
    }
};