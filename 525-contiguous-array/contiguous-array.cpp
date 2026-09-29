class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                nums[i] = -1;
        }
        unordered_map<int, int> mp;
        int pref = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            pref += nums[i];
            if (pref == 0)
                ans = max(ans, i+1);
            if (mp.find(pref) == mp.end())
                mp[pref] = i;
            ans = max(ans, i - mp[pref]);
        }
        return ans;
    }
};