1class Solution {
2public:
3    vector<vector<int>> dp;
4
5    int solve(vector<int>& nums, int idx, int prev) {
6        if (idx == nums.size())
7            return 0;
8
9        if (dp[idx][prev + 1] != -1)
10            return dp[idx][prev + 1];
11
12        int not_pick = solve(nums, idx + 1, prev);
13
14        int pick = 0;
15        if (prev == -1 || nums[idx] > nums[prev]) {
16            pick = 1 + solve(nums, idx + 1, idx);
17        }
18
19        return dp[idx][prev + 1] = max(pick, not_pick);
20    }
21
22    int lengthOfLIS(vector<int>& nums) {
23        dp = vector<vector<int>>(nums.size() + 1,
24                                 vector<int>(nums.size() + 1, -1));
25        return solve(nums, 0, -1);
26    }
27};
28