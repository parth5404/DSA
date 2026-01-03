struct PairHash {
    size_t operator()(const pair<string,int>& p) const {
        return hash<string>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

class Solution {
public:
    string states[12] = {"RYR", "RYG", "RGR", "RGY", "YRY", "YRG",
                         "YGR", "YGY", "GRY", "GRG", "GYR", "GYG"};
    int m = 1e9 + 7;
    unordered_map<pair<string, int>, int,PairHash> dp;
    int solve(string prev_state, int n) {
        if (n == 0)
            return 1;
        if (dp.count({prev_state, n}))
            return dp[{prev_state, n}];
        int res = 0;
        for (int i = 0; i < 12; i++) {
            string curr = states[i];
            bool valid = true;
            for (int j = 0; j < 3; j++) {
                if (prev_state[j] == curr[j]) {
                    valid = false;
                    break;
                }
            }
            if (valid)
                res = (res + solve(curr, n - 1)) % m;
        }
        return dp[{prev_state, n}] = res;
    }
    int numOfWays(int n) {
        int ans = 0;
        for (int i = 0; i < 12; i++) {
            ans = (ans + solve(states[i], n - 1)) % m;
        }
        return ans;
    }
};
