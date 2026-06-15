const int MOD = 1e9 + 7;
const int N = 100010;
int p2[N];
auto init = [] {
    p2[0] = 1;
    for (int i = 1; i < N; i++) {
        p2[i] = p2[i - 1] * 2 % MOD;
    }
    return 0;
}();
class Solution {
public:
    int LOG = 0;
    vector<vector<int>> up;
    void dfs(int child, int parent, unordered_map<int, vector<int>>& mp,
             vector<int>& depth) {
        up[child][0] = parent;
        for (auto it : mp[child]) {
            if (it == parent)
                continue;
            depth[it] = max(depth[it], 1 + depth[child]);
            dfs(it, child, mp, depth);
        }
    }
    int lca(int x, int y, vector<int>& d) {
        if (d[x] > d[y]) {
            swap(x, y);
        }
        for (int i = LOG - 1; i >= 0; i--) {
            if (d[x] <= d[up[y][i]]) {
                y = up[y][i];
            }
        }
        if (x == y) {
            return x;
        }
        for (int i = LOG - 1; i >= 0; i--) {
            if (up[y][i] != up[x][i]) {
                x = up[x][i];
                y = up[y][i];
            }
        }
        return up[x][0];
    }
    int dis(int x, int y, vector<int>& d) {
        return d[x] + d[y] - d[lca(x, y, d)] * 2;
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> mp;
        int n = edges.size();
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
            n = max({n, u, v});
        }
        vector<int> depth(n + 1, 0);
        LOG = (log(n) / log(2)) + 1;
        up = vector<vector<int>>(n + 1, vector<int>(LOG + 1, 0));
        dfs(1, 0, mp, depth);
        for (int node = 1; node <= n; node++) {
            for (int i = 1; i <= LOG; i++) {
                up[node][i] = up[up[node][i - 1]][i - 1];
            }
        }
        vector<int> ans;
        for (auto q : queries) {
            int p = q[0];
            int k = q[1];
            if (p!=k) {
                ans.push_back(p2[dis(p,k,depth)-1]);
            }else{
                ans.push_back(0);
            }
        }

        return ans;
    }
};