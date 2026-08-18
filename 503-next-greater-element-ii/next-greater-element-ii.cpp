class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        int n = nums.size();
        for(int i=n-2;i>=0;i--){
            st.push(nums[i]);
        }

        for(int i=n-1;i>=0;i--){
            int temp = nums[i];
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }
            if(st.empty()){
                nums[i]=-1;
            }
            else{
                nums[i]=st.top();
            }
            st.push(temp);
        }
        return nums;
    }
};