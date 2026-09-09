class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;
        vector<int> arr;
        for (int i = 0; i < ast.size(); i++) {
            while (!st.empty() && st.top() > 0 && ast[i] < 0 &&
                   st.top() < abs(ast[i])) {
                st.pop();
            }
            if (!st.empty() && ast[i] < 0 && st.top() >= abs(ast[i])) {
                if (st.top() == abs(ast[i])) {
                    st.pop();
                }
                continue;
            }
            st.push(ast[i]);
        }
        while (!st.empty()) {
            arr.push_back(st.top());
            st.pop();
        }
        reverse(arr.begin(), arr.end());
        return arr;
    }
};