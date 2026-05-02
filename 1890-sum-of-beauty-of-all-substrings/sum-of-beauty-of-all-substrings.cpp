class Solution {
public:
    int beautySum(string s) {
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            map<char, int> mp;
            mp[s[i]]++;
            for (int j = i + 1; j < s.length(); j++) {
                mp[s[j]]++;
                int mx = 0;
                int mi = INT_MAX;
                for (auto [k, v] : mp) {
                    mx = max(mx, v);
                    mi = min(mi, v);
                }
                cnt+=(mx-mi);
            }
        }
        return cnt;
    }
};