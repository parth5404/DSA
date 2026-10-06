class Solution {
public:
    int longestWPI(vector<int>& hours) {
        for (int i = 0; i < hours.size(); i++) {
            if (hours[i] > 8)
                hours[i] = 1;
            else
                hours[i] = -1;
        }
        int pref = 0;
        int ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < hours.size(); i++) {
            pref += hours[i];
            if (pref > 0)
                ans = max(ans, i + 1);
            if (mp.find(pref - 1) != mp.end())
                ans = max(ans, i - mp[pref - 1]);
            if (mp.find(pref) == mp.end())
                mp[pref] = i;
        }
        return ans;
    }
};