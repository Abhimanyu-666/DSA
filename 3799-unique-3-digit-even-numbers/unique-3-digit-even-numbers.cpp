class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> valid;
        int n = digits.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i == k || j == k || i == j) continue;
                    if (digits[i] == 0) continue;       // no leading zero
                    if (digits[k] % 2 != 0) continue;   // last digit must be even

                    int num = digits[i]*100 + digits[j]*10 + digits[k];
                    valid.insert(num);
                }
            }
        }
        return valid.size();
    }
};