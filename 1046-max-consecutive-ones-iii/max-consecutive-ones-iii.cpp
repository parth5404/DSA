class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros = 0;
        int i = 0;
        int j = 0;
        int sum = 0;
        int ans = 0;
        while (j < nums.size()) {
            if (nums[j] == 0) {
                zeros++;
                // sum++;
                while (zeros > k) {
                    if (nums[i] == 0)
                        zeros--;
                    i++;
                }
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};