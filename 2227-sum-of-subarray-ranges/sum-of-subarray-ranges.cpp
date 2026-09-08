class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int n = nums.size();
        stack<int> st;
        stack<int> st1;
        // st1.push(n - 1);
        // st.push(n - 1);
        vector<int> nge(n, n), nse(n, n);
        vector<int> pge(n, -1), pse(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            while (!st1.empty() && nums[st1.top()] >= nums[i]) {
                st1.pop();
            }
            if (!st.empty())
                nge[i] = st.top();
            if (!st1.empty())
                nse[i] = st1.top();
            st.push(i);
            st1.push(i);
        }
        while (!st.empty()) st.pop();
        while (!st1.empty()) st1.pop();
        for (int i = 0; i < n; i++) {
            // Yahan sirf '<' hai, '<=' nahi!
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            while (!st1.empty() && nums[st1.top()] > nums[i]) {
                st1.pop();
            }
            if (!st.empty())
                pge[i] = st.top();
            if (!st1.empty())
                pse[i] = st1.top();
            st.push(i);
            st1.push(i);
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long max_left = i - pge[i];
            long long max_right = nge[i] - i;
            long long min_left = i - pse[i];
            long long min_right = nse[i] - i;

            ans += (max_left * max_right - min_left * min_right) *
                   (long long)nums[i];
        }
        return ans;
    }
};