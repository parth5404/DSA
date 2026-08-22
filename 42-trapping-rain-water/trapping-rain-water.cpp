class Solution {
public:
    int trap(vector<int>& ht) {
        int n = ht.size();
        int ans = 0;
        vector<int> suff(ht.size(), ht.back());
        for (int i = ht.size() - 2; i >= 0; i--) {
            suff[i] = max(suff[i + 1], ht[i]);
        }
        int left_max = 0;
        for (int i = 0; i < n; i++) {
            ans += max(min(left_max, suff[i]) - ht[i], 0);
            left_max = max(left_max, ht[i]);
        }
        return ans;
    }
};