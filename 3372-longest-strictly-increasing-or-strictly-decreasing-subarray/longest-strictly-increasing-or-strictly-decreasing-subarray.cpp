class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if(nums.size()==1)return 1; 
        int ans = 1;
        int runi = 1;
        int rund = 1;
        for (int i = 0; i <= nums.size() - 2; i++) {
            if (nums[i] < nums[i + 1])
                runi++;
            else {
                runi = 1;
            }

            if (nums[i] > nums[i + 1])
                rund++;
            else {
                rund = 1;
            }
            ans = max(ans, runi);
            ans = max(ans, rund);
        }
        return ans;
    }
};