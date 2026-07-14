class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<vector<vector<int>>> dp;

    int solve(vector<int>& nums, int idx, int g1, int g2) {
        if (idx == nums.size()) {
            return (g1 != -1 && g1 == g2);
        }

        int& ans = dp[idx][g1 + 1][g2 + 1];
        if (ans != -1)
            return ans;

        long long k1 = solve(nums, idx + 1, g1, g2);

        int ng1 = (g1 == -1) ? nums[idx] : gcd(g1, nums[idx]);
        int ng2 = (g2 == -1) ? nums[idx] : gcd(g2, nums[idx]);

        long long k2 = solve(nums, idx + 1, ng1, g2);
        long long k3 = solve(nums, idx + 1, g1, ng2);

        ans = (k1 + k2 + k3) % MOD;
        return ans;
    }

    int subsequencePairCount(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());

        dp.assign(nums.size(),
                  vector<vector<int>>(mx + 2, vector<int>(mx + 2, -1)));

        return (solve(nums, 0, -1, -1)) % MOD;
    }
};