class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int cnt = 0;
        int pref = 0;
        for (int i = 0; i < nums.size(); i++)
            pref += nums[i];
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < nums.size()-1; i++) {
            sum += nums[i];
            if (nums[i] > (pref - sum) / (n - i - 1))
                cnt++;
        }
        return cnt;
    }
};