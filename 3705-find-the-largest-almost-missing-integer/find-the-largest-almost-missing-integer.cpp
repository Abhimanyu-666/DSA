class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());

        vector<int> freq(maxVal + 1, 0);
        vector<int> windowCount(maxVal + 1, 0);

        // Build first window
        for (int i = 0; i < k; i++) {
            freq[nums[i]]++;
        }
        for (int v = 0; v <= maxVal; v++) {
            if (freq[v] > 0) windowCount[v]++;
        }

        // Slide the window
        for (int start = 1; start <= n - k; start++) {
            freq[nums[start - 1]]--;
            freq[nums[start + k - 1]]++;
            for (int v = 0; v <= maxVal; v++) {
                if (freq[v] > 0) windowCount[v]++;
            }
        }

        int ans = -1;
        for (int v = 0; v <= maxVal; v++) {
            if (windowCount[v] == 1) {
                ans = max(ans, v);
            }
        }
        return ans;
    }
};