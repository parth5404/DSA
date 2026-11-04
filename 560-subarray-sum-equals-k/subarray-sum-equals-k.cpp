class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int pref=0;
        int ans=0;
        mp[0]++;
        for(int i=0;i<nums.size();i++){
            pref+=nums[i];
            ans+=mp[pref-k];
            mp[pref]++;
        }
        return ans;
    }
};