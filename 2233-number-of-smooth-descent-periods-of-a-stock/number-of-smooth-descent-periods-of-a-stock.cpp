class Solution {
public:
    long long getDescentPeriods(vector<int>& nums) {
        vector<long long> dp(nums.size(), 0);
        dp[0] = 1;
        long long ans = 0;
        int len = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] - nums[i] == 1) {
                len++;
                dp[i] = dp[i - 1] + len;
            } else {
                len = 1;
                dp[i] = dp[i - 1] + len;
            }
        }
        return dp.back();
    }
};