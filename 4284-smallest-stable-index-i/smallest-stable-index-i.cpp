class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> suff(nums.size(), 0);
        suff.back() = nums.back();
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = min(nums[i], suff[i + 1]);
        }
        int pref = nums[0];
        int ans = pref - suff[0];
        if (ans <= k)
            return 0;
        for (int i = 1; i < nums.size(); i++) {
            pref = max(pref, nums[i]);
            ans = pref - suff[i];
            if (ans <= k) {
                return i;
            }
        }

        return -1;
    }
};