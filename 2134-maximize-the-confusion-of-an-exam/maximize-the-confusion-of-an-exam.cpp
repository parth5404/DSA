class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int ans = 0;
        int j = 0;
        int i = 0;
        unordered_map<char, int> mp;
        int maxi = 0;
        while (j < s.length()) {
            mp[s[j]]++;
            maxi = max(maxi, mp[s[j]]);
            while ((j - i + 1 - maxi) > k) {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                maxi = max(maxi, mp[s[i]]);
                i++;
            }
            if ((j - i + 1 - maxi) <= k) {
                ans = max(ans, j - i + 1);
            }
            j++;
        }
        return ans;
    }
};