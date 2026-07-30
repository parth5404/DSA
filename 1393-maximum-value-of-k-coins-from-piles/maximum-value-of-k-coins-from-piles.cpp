class Solution {
public:
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& piles, int k, int idx1, int idx2) {
        if (k == 0)
            return 0;
        if (idx1 == piles.size()) {
            return -1e9;
        }
        if (dp[k][idx1] != -1e9-1) {
            return dp[k][idx1];
        }
        int ans = dfs(piles, k, idx1 + 1, 0);
        int cnt = 0;
        int sum = 0;
        for (int i = 0; i < piles[idx1].size(); i++) {
            int ans1 = 0;
            if (cnt < k) {
                sum += piles[idx1][i];
                cnt++;
                ans1 = sum + dfs(piles, k - cnt, idx1 + 1, 0);
                ans = max(ans, ans1);
            } else {
                break;
            }
        }
        return dp[k][idx1] = ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        dp = vector<vector<int>>(k + 1, vector<int>(piles.size() + 1, -1e9-1));
        return dfs(piles, k, 0, 0);
    }
};