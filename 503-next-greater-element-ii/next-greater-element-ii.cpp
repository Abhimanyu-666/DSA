class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n);
        stack<int> st;
        for (int i = 2*n - 1 ; i >= 0 ; i--) {
            while (st.size()>0 && arr[st.top()] <= arr[i%n]) {
                st.pop();
            }

            if(st.size()==0) nge[i%n] =  -1 ;
            else nge[i%n] = arr[st.top()];

            st.push(i%n);
        }
        return nge;
    }
};