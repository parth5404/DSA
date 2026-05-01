class Solution {
public:
    unordered_map<int, int> mp;
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0;
        int ini = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ini = ini + nums[i] * i;
        }
        int n = nums.size();
        int ans = ini;
        int prev = ini;
        for (int i = 1; i < n; i++) {
            int curr = prev - sum + n * nums[(n - 1 + i) % n];
            prev = curr;
            ans = max(ans, curr);
        }
        return ans;
    }
};