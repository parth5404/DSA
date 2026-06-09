class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mini = 1e9;
        long long maxi = -1;
        for (int i = 0; i < nums.size(); i++) {
            mini = min(mini, nums[i] * 1LL);
            maxi = max(maxi, nums[i] * 1LL);
        }
        return (long long)k * (maxi - mini);
    }
};