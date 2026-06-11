class Solution {
public:
    static constexpr int mod = 1e9 + 7;
    int qpow(int x, int y) {
        int res = 1;
        for (; y; y >>= 1) {
            if (y & 1) {
                res = 1ll * res * x % mod;
            }
            x = 1ll * x * x % mod;
        }
        return res;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        int cnt = 0;
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            cnt = max({edges[i][0], edges[i][1], cnt});
        }
        vector<int> vis(cnt, 0);
        // sort(edges.begin(), edges.end());
        queue<array<int, 2>> q;
        q.push({1, 0});
        int ans = 0;
        while (!q.empty()) {
            auto [top, lvl] = q.front();
            vis[top - 1] = 1;
            ans = max(ans, lvl);
            q.pop();
            for (auto it : adj[top]) {
                if (vis[it - 1] == 0)
                    q.push({it, lvl + 1});
            }
        }
        int mod = 1e9 + 7;
        cout<<ans<<endl;
        return qpow(2, ans - 1);
    }
};