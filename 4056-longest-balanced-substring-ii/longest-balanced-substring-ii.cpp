class Solution {
public:
    int longestBalanced(string s) {
        return max({calc1(s), calc3(s), calc2(s, 'a', 'b'), calc2(s, 'a', 'c'),
                    calc2(s, 'b', 'c')});
    }
    int calc1(string& s) {
        int ans = 1;
        int cur = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1])
                cur++;
            else
                cur = 1;
            ans = max(ans, cur);
        }
        return ans;
    }

    int calc2(string& s, char a, char b) {
        int ans = 0;
        int i = 0;
        unordered_map<int, int> mp;
        while (i < s.length()) {
            while (i < s.length() && (s[i] != a && s[i] != b))
                i++;
            mp.clear();
            mp[0] = i - 1;
            int cnta = 0;
            int cntb = 0;
            while (i < s.length() && (s[i] == a || s[i] == b)) {
                s[i] == a ? cnta++ : cntb++;
                if (mp.count(cnta - cntb)) {
                    ans = max(ans, i - mp[cnta - cntb]);
                } else {
                    mp[cnta - cntb] = i;
                }
                i++;
            }
        }
        return ans;
    }
    int calc3(string& s) {
        int ans = 0;
        int n = s.length();
        unordered_map<long long, int> mp;
        int cnta = 0, cntb = 0, cntc = 0;
        auto encode = [](int x, int y) {
            return (static_cast<long long>(x) << 32) ^ y;
        };

        mp[encode(0, 0)] = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a')
                cnta++;
            else if (s[i] == 'b')
                cntb++;
            else if (s[i] == 'c')
                cntc++;

            int ab = cnta - cntb;
            int ac = cnta - cntc;

            long long key = encode(ab, ac);

            if (mp.count(key)) {
                ans = max(ans, i - mp[key]);
            } else {
                mp[key] = i;
            }
        }

        return ans;
    }
};