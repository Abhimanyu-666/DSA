class Solution {
public:
    vector<string> res;
    string s;

    void dfs(int i, int leftRem, int rightRem, int balance, string& cur) {
        if (i == (int)s.size()) {
            if (leftRem == 0 && rightRem == 0 && balance == 0)
                res.push_back(cur);
            return;
        }

        char c = s[i];

        // Option 1: remove this char (skip duplicates in a run)
        if (c == '(' && leftRem > 0) {
            if (i == 0 || s[i - 1] != c || true) {
                // find the run: only remove the first char of a run
                if (i == 0 || s[i - 1] != '(' ) {
                    // handled below via run logic
                }
            }
        }

        // Cleaner duplicate handling: process runs of identical parens at once
        if (c == '(' || c == ')') {
            int j = i;
            while (j < (int)s.size() && s[j] == c) j++;
            int runLen = j - i;

            // choose k chars of this run to remove (k from 0..runLen),
            // keep the other runLen-k, then jump to j
            for (int k = 0; k <= runLen; k++) {
                int nl = leftRem, nr = rightRem;
                if (c == '(') { if (k > nl) break; nl -= k; }
                else          { if (k > nr) break; nr -= k; }

                int kept = runLen - k;
                int nb = balance + (c == '(' ? kept : -kept);
                if (nb < 0) continue; // too many ')' kept

                size_t oldSize = cur.size();
                cur.append(kept, c);
                dfs(j, nl, nr, nb, cur);
                cur.resize(oldSize);
            }
        } else {
            cur.push_back(c);
            dfs(i + 1, leftRem, rightRem, balance, cur);
            cur.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string str) {
        s = str;
        int open = 0, leftRem = 0, rightRem = 0;
        for (char c : s) {
            if (c == '(') open++;
            else if (c == ')') {
                if (open > 0) open--;
                else rightRem++;
            }
        }
        leftRem = open;

        string cur;
        dfs(0, leftRem, rightRem, 0, cur);
        return res;
    }
};