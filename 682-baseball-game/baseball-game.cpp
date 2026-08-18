class Solution {
public:
    int calPoints(vector<string>& arr) {
        stack<int> st;
        int n = arr.size();
        for (int i=0 ; i<n ; i++) {
            if (arr[i] == "+") {
                int top1 = st.top(); st.pop();
                int top2 = st.top();
                int sum = top1 + top2;
                st.push(top1);      // put top1 back
                st.push(sum);       // push the new score
            } else if (arr[i] == "D") {
                st.push(2 * st.top());
            } else if (arr[i] == "C") {
                st.pop();
            } else {
                st.push(stoi(arr[i]));  // parse the string as an integer
            }
        }

        int total = 0;
        while (st.size()>0) {
            total += st.top();
            st.pop();
        }
        return total;
    }
};