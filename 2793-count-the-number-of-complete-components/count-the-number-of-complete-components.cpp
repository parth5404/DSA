class Solution {
public:
    vector<int> vis;
    unordered_map<int, vector<int>> adj;
    int k2 = 0;
    int e2 = 0;
    void dfs(int node, int parent) {
        vis[node] = 1;
        k2++;
        for (auto it : adj[node]) {
            e2++;
            if (vis[it] == -1) {
                dfs(it, node);
            }
        }
    }
    void printvis() {
        for (int i = 0; i < vis.size(); i++) {
            cout << vis[i] << " ";
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vis = vector<int>(n, -1);

        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] == -1) {
                k2 = 0;
                e2 = 0;
                int e1 = adj[i].size();
                dfs(i, -1);
                // e2 = e2 / 2;
                if ((k2 * (k2 - 1)) / 2 == e2 / 2)
                    cnt++;
                // if (k2 * e1 == e2) {
                //     cnt++;
                // }
                cout << k2 << " " << e2 << " " << e1 << endl;
                // printvis();
                // cout << endl;
            }
        }
        return cnt;
    }
};