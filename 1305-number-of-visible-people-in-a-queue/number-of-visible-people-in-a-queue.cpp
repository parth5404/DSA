class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& hts) {
        vector<int> ans(hts.size(), 0);
        stack<int> st;
        st.push(hts.back());
        for (int i = hts.size() - 2; i >= 0; i--) {
            int cnt = 0;
            while (!st.empty() && hts[i] > st.top()) {
                st.pop();
                cnt++;
            }
            ans[i] = cnt + (st.empty() ? 0 : 1);
            st.push(hts[i]);
        }
        return ans;
    }
};