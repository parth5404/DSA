class Solution {
public:
    int solve(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        unordered_map<int, int> mp;
        int ans = 0;
        while (j < nums.size()) {
            mp[nums[j]]++;
            while (mp[nums[j]] > k) {
                if (i < j && mp[nums[i]] > 0)
                    mp[nums[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
    int maxSubarrayLength(vector<int>& nums, int k) { return solve(nums, k); }
};