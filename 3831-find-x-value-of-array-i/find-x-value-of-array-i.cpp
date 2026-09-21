class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> abhi_takk(k, 0);
        vector<long long> curr;
        for (int i = 0; i < nums.size(); i++) {
            int v=nums[i]%k;
            vector<long long> curr(k, 0);
            for (int j = 0; j < k; j++) {
                curr[(j * v) % k] += abhi_takk[j];
            }
            curr[nums[i] % k]++;
            for (int j = 0; j < k; j++) {
                ans[j] += curr[j];
            }
            abhi_takk = curr;
        }
        return ans;
    }
};