class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int pref = 1;
        int suff = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (pref == 0)
                pref = 1;
            if (suff == 0) {
                suff = 1;
            }
            suff = suff * nums[nums.size() - 1 - i];
            pref = pref * nums[i];
            maxi = max(maxi, max(suff, pref));
        }
        return maxi;
    }
};