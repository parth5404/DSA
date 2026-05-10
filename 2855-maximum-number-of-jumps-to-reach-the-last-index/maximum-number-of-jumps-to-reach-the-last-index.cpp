class Solution {
public:
vector<int>dp;
    int solve(vector<int>& nums, int targ, int idx) {
        if (idx >= nums.size() - 1)
            return 0;
        int ans = INT_MIN;
        if(dp[idx]!=INT_MIN)return dp[idx];
        for (int i = idx + 1; i < nums.size(); i++) {
            int k = nums[i] - nums[idx];
            if (k >= -targ && k <= targ) {
                ans = max(ans, 1 + solve(nums, targ, i));
            }
        }
        return dp[idx]=ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        dp=vector<int>(nums.size(),INT_MIN);
        int ans = solve(nums, abs(target), 0);
        for(auto it:dp)cout<<it<<endl;
        return dp[0]<0?-1:dp[0];
    }
};