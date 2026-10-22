class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int z = find(nums.begin(), nums.end(), 0) - nums.begin();

        bool cw = true, acw = true;
        for (int k = 1; k < n; k++) {
            if (nums[(z + k) % n] != k)     cw = false;   
            if (nums[(z - k + n) % n] != k) acw = false;  
        }

        int ans = INT_MAX;
        if (cw) {
            ans = min(ans, z);                  
            ans = min(ans, 2 + (n - z) % n);   
        }
        if (acw) {
            ans = min(ans, (z + 1) % n + 1);    
            ans = min(ans, n - z);             
        }
        return ans == INT_MAX ? -1 : ans;
    }
};