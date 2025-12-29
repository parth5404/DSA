class Solution {
public:
    unordered_map<string, vector<char>> mp;
    unordered_map<string, bool> dp;

    bool solve(string bottom) {
        if (bottom.size() == 1) return true;

        if (dp.count(bottom)) return dp[bottom];

        vector<string> next;
        build(bottom, 0, "", next);

        for (string &s : next) {
            if (solve(s)) 
                return dp[bottom] = true;
        }

        return dp[bottom] = false;
    }

    void build(string &bottom, int idx, string curr, vector<string> &next) {
        if (idx == bottom.size() - 1) {
            next.push_back(curr);
            return;
        }

        string key = bottom.substr(idx, 2);
        if (!mp.count(key)) return;

        for (char ch : mp[key]) {
            build(bottom, idx + 1, curr + ch, next);
        }
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto &s : allowed) {
            mp[s.substr(0, 2)].push_back(s[2]);
        }
        return solve(bottom);
    }
};
