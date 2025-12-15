class Solution {
public:
    long long getDescentPeriods(vector<int>& nums) {
        vector<long long> dp(nums.size(), 0);
        dp[0] = 1;
        long long ans = 1;
        int len = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] - nums[i] == 1) {
                len++;
            } else {
                len = 1;
            }
            ans = ans + len;
        }
        return ans;
    }
};