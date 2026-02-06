class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());     
        int i = 0;
        int j = 0;
        int ans = nums.size();
        while (j < nums.size()) {
            if ((long long)k * nums[i] < nums[j]) {
                i++;
                // if(i>j){
                //     j=i;
                // }
            } else {
                ans = min(ans, (int)nums.size() - (j - i + 1));
                j++;
            }
        }
        
        return ans;
    }
};