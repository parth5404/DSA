class Solution {
public:
    vector<array<int, 2>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<bool>> hard_vis(n, vector<bool>(m, 0));
        queue<array<int, 3>> q;
        int tc = 0;
        for (auto it : sources) {
            ans[it[0]][it[1]] = it[2];
            q.push({it[2], it[0], it[1]});
            hard_vis[it[0]][it[1]] = 1;
            tc++;
        }
        int time = 1;

        while (!q.empty()) {
            int sz = q.size();
            map<pair<int, int>, int> updates;
            while (sz--) {
                auto top = q.front();
                q.pop();
                for (auto [x1, y1] : dirs) {
                    int x = x1 + top[1];
                    int y = y1 + top[2];
                    if (x >= n || x < 0 || y >= m || y < 0)
                        continue;
                    if (hard_vis[x][y])
                        continue;
                    updates[{x, y}] = max(updates[{x, y}], top[0]);
                }
            }
            for (auto [cell,colour] : updates) {
                pair<int,int> arr = cell;
                int inti = colour;
                hard_vis[arr.first][arr.second] = 1;
                ans[arr.first][arr.second] = inti;
                q.push({inti, arr.first, arr.second});
            }
        }
        return ans;
    }
};