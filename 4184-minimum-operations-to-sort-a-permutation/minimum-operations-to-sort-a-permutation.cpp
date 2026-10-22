class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int z = find(nums.begin(), nums.end(), 0) - nums.begin();

        // Direction check: 0 se dono taraf circular traverse
        bool cw = true, acw = true;
        for (int k = 1; k < n; k++) {
            if (nums[(z + k) % n] != k)     cw = false;   // right side: 1,2,3...
            if (nums[(z - k + n) % n] != k) acw = false;  // left side:  1,2,3...
        }

        int ans = INT_MAX;
        if (cw) {
            ans = min(ans, z);                  // (1) sirf rotate
            ans = min(ans, 2 + (n - z) % n);    // (2) reverse -> rotate -> reverse
        }
        if (acw) {
            ans = min(ans, (z + 1) % n + 1);    // (3) rotate -> reverse
            ans = min(ans, n - z);              // (4) reverse -> rotate
        }
        return ans == INT_MAX ? -1 : ans;
    }
};