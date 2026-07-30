class Solution {
public:
    vector<vector<long long>> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        int cost = 1;
        int parity = 0;
        // row,col,cost,parity
        vector<vector<vector<long long>>> dist(
            m, vector<vector<long long>>(n, vector<long long>(2, LLONG_MAX)));
        dist[0][0][0] = 1;
        priority_queue<array<long long, 4>, vector<array<long long, 4>>,
                       greater<>>
            pq;
        // cost,row,col,parity
        pq.push({1, 0, 0, 0});
        while (!pq.empty()) {
            auto [cost, row, col, parity] = pq.top();
            pq.pop();
            if (cost > dist[row][col][parity])
                continue;
            int new_parity = 1 - parity;
            if (cost + penalty[row][col] < dist[row][col][new_parity]) {
                dist[row][col][new_parity] = cost + penalty[row][col];
                pq.push({dist[row][col][new_parity], row, col, new_parity});
            }

            for (int k = 0; k < 4; k++) {
                int x = row + dir[k][0];
                int y = col + dir[k][1];
                if (x < 0 || x >= m || y < 0 || y >= n) {
                    continue;
                }
                long long cost1 = (x + 1) * (y + 1);
                bool ok = false;
                if (parity == 1) {
                    if ((x == row - 1 && y == col) ||
                        (x == row && y == col - 1)) {
                        ok = true;
                    }
                } else {
                    if ((x == row + 1 && y == col) ||
                        (x == row && y == col + 1)) {
                        ok = true;
                    }
                }
                if (!ok)
                    cost1 += (long long)penalty[row][col];
                if (cost + cost1 < dist[x][y][new_parity]) {
                    dist[x][y][new_parity] = cost + cost1;
                    pq.push({dist[x][y][new_parity], x, y, new_parity});
                }
            }
        }
        return min(dist[m - 1][n - 1][0], dist[m - 1][n - 1][1]);
    }
};