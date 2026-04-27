class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<vector<int>>> dirs = {
            {},
            {{0,-1},{0,1}},        // 1: left, right
            {{-1,0},{1,0}},        // 2: up, down
            {{0,-1},{1,0}},        // 3: left, down
            {{0,1},{1,0}},         // 4: right, down
            {{0,-1},{-1,0}},       // 5: left, up
            {{0,1},{-1,0}}         // 6: right, up
        };

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        q.push({0,0});
        vis[0][0] = true;

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            if (i == m-1 && j == n-1) return true;

            for (auto d : dirs[grid[i][j]]) {
                int ni = i + d[0];
                int nj = j + d[1];

                if (ni < 0 || nj < 0 || ni >= m || nj >= n || vis[ni][nj])
                    continue;

                for (auto back : dirs[grid[ni][nj]]) {
                    if (ni + back[0] == i && nj + back[1] == j) {
                        vis[ni][nj] = true;
                        q.push({ni, nj});
                        break;
                    }
                }
            }
        }

        return false;
    }
};