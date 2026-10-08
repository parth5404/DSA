class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long neg = LLONG_MIN / 4;
        vector<long long> p0(n, neg), m0(n, neg), m1(n, neg), p1(n, neg);
        long long ans = nums[0];
        p0[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            p0[i] = max(m0[i - 1] + nums[i], nums[i] * 1LL);
            m0[i] = p0[i - 1] - nums[i];
            p1[i] = m1[i - 1] + nums[i];
            m1[i] = p1[i - 1] - nums[i];
            if (i >= 2) {
                p1[i] = max(m0[i - 2] + nums[i], p1[i]);
                m1[i] = max(p0[i - 2] - nums[i], m1[i]);
            }
            ans = max({ans, p1[i], m1[i], p0[i], m0[i]});
        }
        return ans;
    }
};