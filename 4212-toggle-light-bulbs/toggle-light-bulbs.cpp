class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        map<int, bool> mp;
        for (auto it : bulbs) {
            if (mp.count(it))
                mp[it] = !mp[it];
            else
                mp[it] = 1;
        }
        vector<int> ans;
        for (auto it : mp) {
            if (it.second)
                ans.push_back(it.first);
        }
        return ans;
    }
};