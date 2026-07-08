class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<long long> pow10(s.size() + 1, 1);
        int MOD = 1e9 + 7;
        for (int i = 1; i <= s.size(); i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        vector<array<long long, 3>> vec(s.size(), {0, 0});
        // sum,x

        int power = 0;
        if (s[0] - '0' != 0) {
            vec[0][0] = s[0] - '0';
        }
        for (int i = 1; i < s.length(); i++) {
            vec[i][0] = vec[i - 1][0] + s[i] - '0';
        }
        if (s[0] - '0' != 0) {
            vec[0][1] = (s[0] - '0') * pow(10, power);
            power++;
            vec[0][2] = power;
        }
        for (int i = 1; i < s.length(); i++) {
            if (s[i] - '0' != 0) {
                vec[i][1] =( vec[i - 1][1] * 10 + (s[i] - '0'))%MOD;
                power++;
                vec[i][2] = power;
            } else {
                vec[i][1] = (vec[i - 1][1])%MOD;
                vec[i][2] = vec[i - 1][2];
            }
        }
        vector<int> ans;
        for (auto q : queries) {
            int l = q[0];
            int r = q[1];
            long long sum = vec[r][0] - (l ? vec[l - 1][0] : 0);
            int digits = vec[r][2] - (l ? vec[l - 1][2] : 0);
            long long left = (l ? vec[l - 1][1] : 0);
            long long x = (vec[r][1] - left * pow10[digits] % MOD + MOD) % MOD;
            ans.push_back((x * sum) % MOD);
        }
        return ans;
    }
};