class Solution {
public:
    vector<int> nums1;
    vector<int> nums2;
    int n;
    vector<vector<array<int, 2>>> memo;
    array<int, 2> dp(int idx, int state) {
        if (idx == n)
            return {0, 0};
        if (memo[idx][state][0] != -1)
            return memo[idx][state];
        int val1 = 0;
        int val2 = 0;
        if (state == 1) {
            auto a = dp(idx + 1, 2);
            auto b = dp(idx + 1, 1);
            val1 = nums1[idx] + max(a[0], b[0]);
            val2 = nums2[idx] + max(a[1], b[1]);
        }
        else if (state == 2) {
            auto a = dp(idx + 1, 2);
            auto b = dp(idx + 1, 3);
            val1 = max(
                nums2[idx] + a[0],
                nums1[idx] + b[0]
            );
            val2 = max(
                nums1[idx] + a[1],
                nums2[idx] + b[1]
            );
        }
        else {
            auto a = dp(idx + 1, 3);
            val1 = nums1[idx] + a[0];
            val2 = nums2[idx] + a[1];
        }
        return memo[idx][state] = {val1, val2};
    }

    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        n = nums1.size();
        memo.assign(n, vector<array<int, 2>>(4, {-1, -1}));
        auto ans = dp(0, 1);
        return max(ans[0], ans[1]);
    }
};