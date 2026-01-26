class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int j = 0;
        unordered_map<int, int> mp;
        int pref = 0;
        int ans = 0;
        mp[0] = 1;
        while (j < nums.size()) {
            pref += nums[j];
            ans += mp[pref - goal];
            mp[pref]++;
            j++;
        }
        return ans;
    }
};