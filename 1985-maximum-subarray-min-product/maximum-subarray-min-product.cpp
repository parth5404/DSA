class Solution {
public:
    int maxSumMinProduct(vector<int>& n) {
        long res = 0;
        vector<long> dp(n.size()), st;
        vector<int> lt(n.size(), -1), rt(n.size(), n.size());
        dp[0] = n[0];
        for (int i = 1; i < n.size(); ++i)
            dp[i] = dp[i - 1] + n[i];
        for (int i = 0; i < n.size(); ++i) {
            while (!st.empty() && (n[st.back()] >= n[i])) {
                st.pop_back();
            }
            if (!st.empty()) {
                lt[i] = st.back();
            }
            st.push_back(i);
        }
        st.clear();
        for (int i = n.size() - 1; i >= 0; i--) {
            while (!st.empty() && (n[st.back()] >= n[i])) {
                st.pop_back();
            }
            if (!st.empty()) {
                rt[i] = st.back();
            }
            st.push_back(i);
        }
        for (int i = 0; i < n.size(); i++) {
            long rt1 = dp[rt[i] - 1];
            long lt1 = (lt[i] == -1) ? 0 : dp[lt[i]];
            long val = ((rt1 - lt1) * n[i]);
            res = max(res, val);
        }

        return res % 1000000007;
    }
};