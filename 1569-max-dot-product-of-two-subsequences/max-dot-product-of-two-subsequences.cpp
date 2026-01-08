class Solution {
public:
    vector<int> nums1;
    vector<int> nums2;
    vector<vector<int>> dp;
    int solve(int i, int j, int m, int n) {
        if (i == m || j == n)
            return -1e9;
        if (dp[i][j] != -1e9)
            return dp[i][j];
        int val = nums1[i] * nums2[j];
        int case1 = solve(i + 1, j, m, n);
        int case2 = solve(i, j + 1, m, n);
        int case3 = val + solve(i + 1, j + 1, m, n);
        return dp[i][j] = max({val, case1, case2, case3});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        this->dp = vector<vector<int>>(nums1.size() + 1,
                                       vector<int>(nums2.size() + 1, -1e9));
        return solve(0, 0, nums1.size(), nums2.size());
    }
};