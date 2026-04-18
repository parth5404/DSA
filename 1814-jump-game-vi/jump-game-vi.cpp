class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& nums, int idx, int k) {
        if (idx >= nums.size())
            return 0;
        if (idx == nums.size() - 1)
            return nums[idx];

        if (dp[idx] != INT_MIN)
            return dp[idx];

        int ans = INT_MIN;

        for (int i = idx + 1; i <= idx + k && i < nums.size(); i++) {
            ans = max(ans, nums[idx] + solve(nums, i, k));
        }

        return dp[idx] = ans;
    }
    int maxResult(vector<int>& nums, int k) {
        // vector<int> pref(nums.size(), 0);
        // pref[0] = nums[0];
        // for (int i = 1; i < nums.size(); i++)
        //     pref[i] = nums[i] + pref[i - 1];
        this->dp = vector<int>(nums.size(), INT_MIN);
        dp[0] = nums[0];
        multiset<int>ms;
        ms.insert(dp[0]);
        for (int i = 1; i < nums.size(); i++) {
            // for (int j = 1; j <= k && i - j >= 0; j++) {
            //     dp[i] = max(dp[i], dp[i-j] + nums[i]);
            // }
            if(i>k)ms.erase(ms.find(dp[i-k-1]));
            dp[i]=nums[i]+(*ms.rbegin());
            ms.insert(dp[i]);
        }
        return dp.back();
    }
};