class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                heights[j] = (matrix[i][j] == '0') ? 0 : heights[j] + 1;
            }
            maxArea = max(maxArea, largestRectangleInHistogram(heights));
        }

        return maxArea;
    }

private:
    int largestRectangleInHistogram(vector<int>& heights) {
        stack<int> st; // stores indices, monotonically increasing heights
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            int curHeight = (i == n) ? 0 : heights[i]; // sentinel to flush stack at end

            while (!st.empty() && heights[st.top()] > curHeight) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        return maxArea;
    }
};