class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        vector<pair<int, int>> st;
        long long ans = 0, tot = 0;
        for (int v : nums) {
            while (!st.empty() && v < st.back().first) {
                tot -= st.back().second;
                st.pop_back();
            }
            if (!st.empty() && st.back().first == v) {
                ans+=tot-st.back().second;
                tot++;
                st.back().second++;
            } else {
                ans += tot;
                st.push_back({v, 1});
                tot++;
            }
        }
        return ans;
    }
};