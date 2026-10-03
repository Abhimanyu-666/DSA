class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // sentinel: "index before start"
        int maxLen = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else { // s[i] == ')'
                st.pop();
                if (st.empty()) {
                    st.push(i); // new base: this ')' is unmatched
                } else {
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }

        return maxLen;
    }
};