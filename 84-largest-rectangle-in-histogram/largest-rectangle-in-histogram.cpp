class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans = 0;
        for (int i = 0; i <= heights.size(); i++) {
            int curr = (i == heights.size()) ? 0 : heights[i];
            while (!st.empty() && heights[st.top()] > curr) {
                int height = heights[st.top()];
                st.pop();
                int left = st.empty() ? -1 : st.top();
                ans = max(ans, height * (i - left - 1));
            }
            st.push(i);
        }
        return ans;
    }
};