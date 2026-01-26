class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int odds = 0;
        int ans = 0;
        int j = 0;
        int i = 0;
        int cnt = 0;
        while (j < nums.size()) {
            if (nums[j] % 2 == 1) {
                odds++;
                cnt = 0;
            }
            while (odds == k) {
                if (nums[i] % 2 == 1)
                    odds--;
                i++;
                cnt++;
            }
            ans+=cnt;
            j++;
        }
        return ans;
    }
};