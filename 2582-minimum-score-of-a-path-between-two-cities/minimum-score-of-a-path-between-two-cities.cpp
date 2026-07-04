class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<array<int, 2>>> adj;

        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<int> vis(n + 1, 0);
        queue<int> q;
        q.push(1);
        vis[1] = 1;

        int ans = INT_MAX;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto& [v, w] : adj[u]) {
                ans = min(ans, w);
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }

        return ans;
    }
};