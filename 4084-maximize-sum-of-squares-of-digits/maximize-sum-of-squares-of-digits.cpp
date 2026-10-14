class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if ((long long)sum > 9LL * num) return "";

        int full = sum / 9;
        int rem = sum % 9;

        string ans(full, '9');
        if (rem > 0) ans += char('0' + rem);
        ans.append(num - ans.size(), '0');

        return ans;
    }
};