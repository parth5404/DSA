class Solution {
public:
    int longestWPI(vector<int>& hrs) {
        unordered_map<int, int> mp;
        int pref = 0;
        int ans = 0;
        for (int i = 0; i < hrs.size(); i++) {
            if (hrs[i] > 8) {
                pref++;
            } else {
                pref--;
            }
            if (mp.find(pref) == mp.end()) {
                mp[pref] = i;
            }

            if (pref > 0)
                ans = max(ans, i + 1);
            if (mp.find(pref - 1) != mp.end()) {
                ans = max(ans, i - mp[pref - 1]);
            }
        }

        return ans;
    }
};