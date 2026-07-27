class Solution {
public:
    using ll = long long;
    const ll INF = 4e18;

    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        int N = m * n;

        auto id = [&](int x, int y) {
            return x * n + y;
        };

        vector<vector<ll>> dist(N, vector<ll>(2, INF));
        // parity = 0 -> next action is odd
        // parity = 1 -> next action is even

        using T = tuple<ll, int, int>; // cost, node, parity
        priority_queue<T, vector<T>, greater<T>> pq;

        dist[0][0] = 1; // cost to enter (0,0)
        pq.push({1, 0, 0});

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [cost, v, par] = pq.top();
            pq.pop();

            if (cost != dist[v][par]) continue;

            int x = v / n;
            int y = v % n;

            // Wait
            {
                ll nc = cost + penalty[x][y];
                if (nc < dist[v][par ^ 1]) {
                    dist[v][par ^ 1] = nc;
                    pq.push({nc, v, par ^ 1});
                }
            }

            // Move
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

                bool followsRule;
                if (par == 0) {
                    // odd action: right or down
                    followsRule = (dx[k] == 1 || dy[k] == 1);
                } else {
                    // even action: left or up
                    followsRule = (dx[k] == -1 || dy[k] == -1);
                }

                ll add = 1LL * (nx + 1) * (ny + 1);
                if (!followsRule) add += penalty[x][y];

                int to = id(nx, ny);
                ll nc = cost + add;

                if (nc < dist[to][par ^ 1]) {
                    dist[to][par ^ 1] = nc;
                    pq.push({nc, to, par ^ 1});
                }
            }
        }

        int target = id(m - 1, n - 1);
        return min(dist[target][0], dist[target][1]);
    }
};