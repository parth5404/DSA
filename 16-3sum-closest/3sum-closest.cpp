class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = 1e5;
        int ans = 0;
        for (int k = 0; k < nums.size(); k++) {
            for (int i = k + 1; i < nums.size(); i++) {
                for (int j = i + 1; j < nums.size(); j++) {
                    if (abs(target - (nums[i] + nums[j] + nums[k])) < diff) {
                        diff = abs(target - (nums[i] + nums[j] + nums[k]));
                        ans = nums[i] + nums[j] + nums[k];
                    }
                }
            }
        }
        return ans;
    }
};