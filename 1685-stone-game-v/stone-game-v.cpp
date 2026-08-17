class Solution {
public:
    vector<long long> pref;
    vector<vector<int>> memo;
    int dp(vector<long long>& pref, int s, int e) {
        if (s == e)
            return 0;

        if (memo[s][e] != -1) {
            return memo[s][e];
        }
        int ans = 0;
        for (int i = s; i < e; i++) {
            int left_sum = pref[i] - (s > 0 ? pref[s - 1] : 0);
            int right_sum = pref[e] - pref[i];
            if (left_sum < right_sum) {
                ans = max(ans, left_sum + dp(pref, s, i));
            }
            if (right_sum < left_sum) {
                ans = max(ans, right_sum + dp(pref, i + 1, e));
            }
            if (right_sum == left_sum) {
                ans = max(ans, left_sum + dp(pref, s, i));
                ans = max(ans, right_sum + dp(pref, i + 1, e));
            }
        }
        return memo[s][e] = ans;
    }
    int stoneGameV(vector<int>& st) {
        vector<long long> pref(st.size(), 0);
        pref[0] = st[0];
        for (int i = 1; i < st.size(); i++) {
            pref[i] = pref[i - 1] + st[i];
        }
        this->pref = pref;
        this->memo = vector<vector<int>>(503, vector<int>(501, -1));
        return dp(pref, 0, st.size() - 1);
    }
};