class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long total = 0;
        for (int num : nums) total += num;
        
        long long target = total - x;
        
        // Edge cases: target < 0 means x is too large even removing everything
        if (target < 0) return -1;
        if (target == 0) return n; // remove all elements
        
        int left = 0;
        long long windowSum = 0;
        int maxLen = -1;
        
        for (int right = 0; right < n; right++) {
            windowSum += nums[right];
            
            // Shrink window while sum exceeds target
            while (windowSum > target && left <= right) {
                windowSum -= nums[left];
                left++;
            }
            
            if (windowSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }
        
        return maxLen == -1 ? -1 : n - maxLen;
    }
};