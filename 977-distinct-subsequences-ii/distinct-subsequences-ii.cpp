class Solution {
public:
    int distinctSubseqII(string s) {
        long long prev = 1;
        vector<long long> last_seen(26, 0);
        last_seen[s[0] - 'a']++;
        int mod = 1e9 + 7;
        for (int i = 1; i < s.length(); i++) {
            long long old_prev = prev;
            prev = (2 * prev + 1 - last_seen[s[i] - 'a'] + mod) % mod;
            last_seen[s[i] - 'a'] = old_prev + 1;
        }
        return prev;
    }
};