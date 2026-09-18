class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, l=0 , r=0 ;
        while(r < nums.size()-1){
            int far = 0;
            for(int i=l ; i<=r ; i++){
                far = max(far,i+nums[i]); // to calculate how far does each idx int the given range go 
            }
            l = r+1;// update left to the next idx of r
            r = far;// update r to the farthest idx possible from the given range
            jumps++;
        }
        return jumps;
    }
};