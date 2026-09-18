class Solution {
public:
    bool canJump(vector<int>& nums) {
        // initiize max idx
        int maxIdx = 0;
        int n = nums.size();
        for(int i=0 ; i<n ; i++){
            if(i>maxIdx) return false; // as we cant reach i if max idx is not >= i
            maxIdx = max(maxIdx, i+nums[i]);
        }
        return true;

    }
};