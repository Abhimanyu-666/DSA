class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int need = 0;  // number of ')' still required

        for (char ch : s) {
            if (ch == '(') {
                if (need % 2 == 1) {   // previous '(' has only one ')'
                    ans++;             // insert a ')' to complete it
                    need--;
                }
                need += 2;
            } else {
                need--;
                if (need == -1) {      // unmatched ')': insert a '('
                    ans++;
                    need = 1;          // new '(' needs 2, current ')' gave 1
                }
            }
        }

        return ans + need;
    }
};