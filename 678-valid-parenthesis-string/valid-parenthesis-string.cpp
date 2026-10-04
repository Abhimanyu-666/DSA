class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0; // range of possible open-paren counts

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low--;
                high--;
            } else { // '*'
                low--;
                high++;
            }

            if (high < 0) return false; // too many ')' even in best case
            if (low < 0) low = 0; // can't have negative opens; clamp
        }

        return low == 0;
    }
};