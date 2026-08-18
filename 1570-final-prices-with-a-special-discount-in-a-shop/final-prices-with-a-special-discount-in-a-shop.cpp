class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res = prices;// deep copy of prices
        stack<int> st;
        int n = prices.size();
        for(int i=0 ; i<n ; i++){
            while(st.size()>0 && prices[st.top()] >= prices[i]){
                // apply discount
                res[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        } 
        return res;
    }
};