class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i = 0;
        long long sum = 0, ans = 0;
        unordered_set<int> st;
        int j = 0;
        while (j < nums.size()) {
            while (st.count(nums[j])) {
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            sum += nums[j];
            st.insert(nums[j]);
            if (j - i + 1 > k) {
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            if (j - i + 1 == k) {
                ans = max(ans, sum);
            }
            j++;
        }
        return ans;
    }
};
