class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& nums, int idx, int prev) {
        if (idx == nums.size())
            return 0;

        if (dp[idx][prev + 1] != -1)
            return dp[idx][prev + 1];

        int not_pick = solve(nums, idx + 1, prev);

        int pick = 0;
        if (prev == -1 || nums[idx] > nums[prev]) {
            pick = 1 + solve(nums, idx + 1, idx);
        }

        return dp[idx][prev + 1] = max(pick, not_pick);
    }

    int lengthOfLIS(vector<int>& nums) {
        dp = vector<vector<int>>(nums.size() + 1,
                                 vector<int>(nums.size() + 1, -1));
        return solve(nums, 0, -1);
    }
};
