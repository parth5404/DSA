class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans = 0;
        int i = 0;
        int j = 0;
        unordered_map<int, int> mp;
        while (j < s.length()) {
            mp[s[j]]++;
            if (mp[s[j]] == 2) {
                ans = max(ans, j - i + 1);
            }
            while (mp[s[j]] > 2) {
                mp[s[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};