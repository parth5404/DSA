class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, long long> mp;
        long long pref = 0;
        long long ans = LLONG_MIN;
        for (int i = 0; i < nums.size(); i++) {
            pref += nums[i];
            if (mp.find(nums[i] - k) != mp.end()) {
                ans = max(ans, pref - mp[nums[i] - k] + nums[i] - k);
            }
            if (mp.find(nums[i] + k) != mp.end()) {
                ans = max(ans, pref - mp[nums[i] + k] + nums[i] + k);
            }
            if (mp.find(nums[i]) != mp.end()) {
                mp[nums[i]] = min(mp[nums[i]], pref);
            } else {
                mp[nums[i]] = pref;
            }
        }
        if (ans == LLONG_MIN)
            return 0;
        return ans;
    }
};