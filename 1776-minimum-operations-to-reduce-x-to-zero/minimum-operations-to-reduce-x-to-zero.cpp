class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int val = total - x;
        if (val < 0)
            return -1;
        int i = 0;
        int j = 0;
        int ans = -1;
        int run = 0;
        while (j < nums.size()) {
            run += nums[j];
            while (i <= j && run > val) {
                run -= nums[i];
                i++;
            }
            if (run == val) {
                ans = max(ans, j - i + 1);
            }
            j++;
        }
        if (ans == -1)
            return -1;
        return nums.size() - ans;
    }
};