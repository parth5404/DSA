class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int i = 0;
        int j = 0;
        long long ans = 0;
        set<pair<long long,int>> st;
        while (j < nums.size()) {
            st.insert({nums[j],j});
            auto maxi = *st.rbegin();
            auto mini = *st.begin();
            while (i <= j && (maxi.first - mini.first)*1LL* (j - i + 1) > k) {
                st.erase({nums[i],i});
                maxi = *st.rbegin();
                mini = *st.begin();
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
};