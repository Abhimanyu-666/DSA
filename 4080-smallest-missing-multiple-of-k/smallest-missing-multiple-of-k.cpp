class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> present(nums.begin(), nums.end());
        int m = k;
        while (present.count(m)) {
            m += k;
        }
        return m;
    }
};