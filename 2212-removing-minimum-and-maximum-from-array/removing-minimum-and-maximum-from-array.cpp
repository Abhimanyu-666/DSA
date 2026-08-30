class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0, maxIdx = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }

        int i = min(minIdx, maxIdx);
        int j = max(minIdx, maxIdx);

        int removeFromFront = j + 1;                  // delete up through the later index
        int removeFromBack = n - i;                   // delete from the earlier index to the end
        int removeBothEnds = (i + 1) + (n - j);        // earlier from front, later from back

        return min({removeFromFront, removeFromBack, removeBothEnds});
    }
};