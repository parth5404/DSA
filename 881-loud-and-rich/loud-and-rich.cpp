class Solution {
public:
    unordered_map<int, vector<int>> mp;
    vector<int> ans;
    int dfs(int idx, vector<int>& qt) {
        if (ans[idx] != -1) {
            return ans[idx];
        }
        int ans1 = idx;
        for (int i = 0; i < mp[idx].size(); i++) {
            int dfs1 = dfs(mp[idx][i], qt);
            if (qt[dfs1] < qt[ans1]) {
                ans1 = dfs1;
            }
        }
        return ans[idx] = ans1;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        for (int i = 0; i < richer.size(); i++) {
            mp[richer[i][1]].push_back(richer[i][0]);
        }
        this->ans = vector<int>(quiet.size(), -1);

        for (int j = 0; j < ans.size(); j++) {
            ans[j] = dfs(j, quiet);
        }

        return ans;
    }
};