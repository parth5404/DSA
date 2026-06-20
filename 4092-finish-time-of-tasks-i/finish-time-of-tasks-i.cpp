class Solution {
public:
    long long dfs(int n, unordered_map<int, vector<int>>& mp, int node,
                  vector<int>& bt) {
        if (!mp.count(node)) {
            return bt[node];
        }
        long long mini = LLONG_MAX;
        long long maxi = LLONG_MIN;
        for (auto it : mp[node]) {
            long long call = dfs(n, mp, it, bt);
            mini = min(mini, call);
            maxi = max(maxi, call);
        }
        return (2*1LL*maxi - mini) + bt[node] ;
    }
    long long finishTime(int n, vector<vector<int>>& edges,
                         vector<int>& baseTime) {
        unordered_map<int, vector<int>> mp;
        for (auto it : edges) {
            mp[it[0]].push_back(it[1]);
        }
        return dfs(n, mp, 0, baseTime);
    }
};