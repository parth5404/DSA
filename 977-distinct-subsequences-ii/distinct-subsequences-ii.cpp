class Solution {
public:
    int distinctSubseqII(string s) {
        int mod = 1e9 + 7;
        long long prev = 1;
        vector<long long> last(26, 0);
        last[s[0] - 'a'] = prev;
        for (int i = 1; i < s.length(); i++) {
            long long oldPrev = prev;
            int idx = s[i] - 'a';
            prev = (prev * 2 + 1 - last[idx] + mod) % mod;
            last[idx] = oldPrev + 1;
        }
        return prev;
    }
};