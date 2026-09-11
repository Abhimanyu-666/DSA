class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int cnt[10] = {0};
        for (int d : digits) cnt[d]++;

        int count = 0;
        for (int num = 100; num < 1000; num += 2) {
            int need[10] = {0};
            int temp = num;
            for (int i = 0; i < 3; i++) {
                need[temp % 10]++;
                temp /= 10;
            }

            bool ok = true;
            for (int i = 0; i < 10; i++) {
                if (need[i] > cnt[i]) { ok = false; break; }
            }
            if (ok) count++;
        }
        return count;
    }
};