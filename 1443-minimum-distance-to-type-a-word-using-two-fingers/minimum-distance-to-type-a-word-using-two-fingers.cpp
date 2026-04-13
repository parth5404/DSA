class Solution {
public:
    map<char, vector<int>> mp;
    map<vector<int>,int>dp;
    int solve(string& word, int f1x, int f1y, int f2x, int f2y, int idx) {
        if(idx>=word.length()){
            return 0;
        }
        if(dp.count({f1x,f1y,f2x,f2y,idx})){
            return dp[{f1x,f1y,f2x,f2y,idx}];
        }
        int cost = INT_MAX;
        if (f1x == -1 && f1y == -1 && f2x == -1 && f2y == -1) {
            int c1 = 0 + solve(word, mp[word[idx]][0], mp[word[idx]][1], f2x,
                               f2y, idx + 1);
            int c2 = 0 + solve(word, f1x, f1y, mp[word[idx]][0],
                               mp[word[idx]][1], idx + 1);
            cost = min({cost, c1, c2});
        }
        if (f1x == -1 && f1y == -1 && f2x != -1 && f2y != -1) {
            int c1 = 0 + solve(word, mp[word[idx]][0], mp[word[idx]][1], f2x,
                               f2y, idx + 1);
            int c2 = abs(mp[word[idx]][0] - f2x) + abs(mp[word[idx]][1] - f2y) +
                     solve(word, f1x, f1y, mp[word[idx]][0], mp[word[idx]][1],
                           idx + 1);
            cost = min({cost, c1, c2});
        }
        if (f1x != -1 && f1y != -1 && f2x == -1 && f2y == -1) {
            int c1 = 0 + solve(word, f1x, f1y, mp[word[idx]][0],
                               mp[word[idx]][1], idx + 1);
            int c2 = abs(mp[word[idx]][0] - f1x) + abs(mp[word[idx]][1] - f1y) +
                     solve(word, mp[word[idx]][0], mp[word[idx]][1], f2x,
                           f2y, idx + 1);
            cost = min({cost, c1, c2});
        }
        if (f1x != -1 && f1y != -1 && f2x != -1 && f2y != -1) {
            int c1 = abs(mp[word[idx]][0] - f1x) + abs(mp[word[idx]][1] - f1y) +
                     solve(word, mp[word[idx]][0], mp[word[idx]][1], f2x, f2y,
                           idx + 1);
            int c2 = abs(mp[word[idx]][0] - f2x) + abs(mp[word[idx]][1] - f2y) +
                     solve(word, f1x, f1y, mp[word[idx]][0], mp[word[idx]][1],
                           idx + 1);
            cost = min({cost, c1, c2});
        }
        return dp[{f1x,f1y,f2x,f2y,idx}]=cost;
    }
    int minimumDistance(string word) {
        map<char, vector<int>> mp;
        int cnt = 0;
        for (int i = 0; i <= 3; i++) {
            for (int j = 0; j < 6; j++) {
                mp[cnt + 'A'] = {i, j};
                cnt++;
            }
        }
        mp['Y'] = {4, 0};
        mp['Z'] = {4, 1};
        this->mp = mp;
        return solve(word,-1,-1,-1,-1,0);
    }
};