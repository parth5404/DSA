class Solution {
public:
    vector<array<int, 2>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int trapRainWater(vector<vector<int>>& hp) {
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        int n = hp.size();
        int m = hp[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i <= n - 1; i++) {
            if (i == 0 || i == n - 1) {
                for (int j = 0; j <= m - 1; j++) {
                    pq.push({hp[i][j], i, j});
                    vis[i][j] = 1;
                }
            } else {
                pq.push({hp[i][0], i, 0});
                pq.push({hp[i][m - 1], i, m - 1});
                vis[i][0] = 1;
                vis[i][m - 1] = 1;
            }
        }
        int ans=0;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            for (int i = 0; i < dirs.size(); i++) {
                int x = top[1] + dirs[i][0];
                int y = top[2] + dirs[i][1];
                if (x < 0 || x > n - 1 || y < 0 || y > m - 1)
                    continue;
                if (vis[x][y] == 1)
                    continue;
                if (hp[x][y] < top[0]) {
                    ans += (top[0] - hp[x][y]);
                }
                pq.push({max(top[0], hp[x][y]), x, y});
                vis[x][y] = 1;
            }
        }
        return ans;
    }
};