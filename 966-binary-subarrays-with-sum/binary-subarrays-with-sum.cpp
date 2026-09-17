class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int pref = 0;
        unordered_map<int, int> mp;
        mp[0]=1;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            pref+=nums[i];
            ans+=mp[pref-goal];
            mp[pref]++;
        }
        return ans;
    }
};