class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pre(n);
        for (int i = 0; i < n; i++) {
            long long v = (i % 2 == 0) ? nums[i] : -(long long)nums[i];
            pre[i] = (i == 0 ? 0 : pre[i - 1]) + v;
        }
        long long base = pre[n - 1];
        long long gain = 0;
        long long neg = LLONG_MIN / 4;
        long long evenL = neg, oddL = neg, evenBefore = neg, oddBefore = neg;
        for (int r = 0; r < n; r++) {
            long long before = (r >= 1) ? pre[r - 1] : 0;
            if (r % 2 == 0) {
                gain = max(gain, 2 * (max(evenL, oddBefore) - pre[r]));
                evenBefore = max(before, evenBefore); // odd -> even
                evenL = max(evenL, pre[r]);
            } else {
                gain = max(gain, 2 * (max(oddL, evenBefore) - pre[r]));
                oddBefore = max(before, oddBefore); // even -> odd
                oddL = max(oddL, pre[r]);
            }
        }
        return base + gain;
    }
};