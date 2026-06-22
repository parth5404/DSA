class Solution {
public:
    vector<array<int, 2>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int minimumEffortPath(vector<vector<int>>& hts) {
        int n = hts.size();
        int m = hts[0].size();
        priority_queue<array<int, 3>, vector<array<int, 3>>,
                       greater<array<int, 3>>>
            pq;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        pq.push({0, 0, 0});
        dist[0][0] = 0;
        while (!pq.empty()) {
            auto [ewt, r, c] = pq.top();
            pq.pop();
            for (int i = 0; i < 4; i++) {
                int x = r + dir[i][0];
                int y = c + dir[i][1];
                if (x >= 0 && x < n && y >= 0 && y < m) {
                    int edge = abs(hts[x][y] - hts[r][c]);
                    int newt = max(ewt, edge);
                    if (newt < dist[x][y]) {
                        dist[x][y] = newt;
                        pq.push({newt, x, y});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};