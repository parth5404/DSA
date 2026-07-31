class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mp(26, 0);
        for (int i = 0; i < word.length(); i++)
            mp[word[i] - 'a']++;
        int cnt = 0;

        sort(mp.begin(), mp.end());
        int ans = 0;

        for (int i = 25; i >= 0; i--) {
            ans = ans + ((cnt / 8) + 1) * mp[i];
            cnt++;
        }
        return ans;
    }
};