class Solution {
public:
    vector<long long> dp;
    int dfs(vector<int>& nums, int idx) {
        if (idx >= nums.size())
            return 0;
        if (dp[idx] != -1e10) {
            return dp[idx];
        }
        int inf = -1e9;
        int ans1 = inf, ans2 = inf, ans3 = inf;
        int lst = idx;
        int pref = nums[idx];
        ans1 = pref - dfs(nums, lst + 1);
        if (idx + 1 < nums.size()) {
            pref = nums[idx] + nums[idx + 1];

            lst = idx + 1;
            ans2 = pref - dfs(nums, lst + 1);
        }
        if (idx + 2 < nums.size()) {
            pref = nums[idx] + nums[idx + 1] + nums[idx + 2];
            lst = idx + 2;
            ans3 = pref - dfs(nums, lst + 1);
        }

        return dp[idx] = max({ans1, ans2, ans3});
    }
    string stoneGameIII(vector<int>& sv) {
        dp = vector<long long>(sv.size() + 1, -1e10);
        int n = sv.size();
        dp[n] = 0;
        dp[n - 1] = sv[n - 1];
        if (n - 2 >= 0) {
            dp[n - 2] = max((sv[n - 2] - dp[n - 1]) * 1LL,
                            (sv[n - 2] + sv[n - 1]) * 1LL);
        }
        for (int i = n - 3; i >= 0; i--) {
            dp[i] = max({sv[i] - dp[i + 1], sv[i] + sv[i + 1] - dp[i + 2],
                         sv[i] + sv[i + 1] + sv[i + 2] - dp[i + 3]});
        }
        // int ans = dfs(sv, 0);
        return (dp[0] > 0) ? "Alice" : (dp[0] == 0) ? "Tie" : "Bob";
    }
};