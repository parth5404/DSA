class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1e9 + 7;
        unordered_map<int, vector<array<int, 2>>> mp;
        for (auto it : roads) {
            mp[it[0]].push_back({it[1], it[2]});
            mp[it[1]].push_back({it[0], it[2]});
        }
        vector<array<long long, 2>> dist(n, {(long long)1e18, 0});
        dist[0][0] = 0;
        dist[0][1] = 1;
        priority_queue<array<long long, 2>, vector<array<long long, 2>>,
                       greater<array<long long, 2>>>
            pq;
        pq.push({0, 0});
        // wt,ways
        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();
            if (time > dist[node][0])
                continue;
            for (auto [v, wt] : mp[node]) {
                if (time + wt == dist[v][0]) {
                    dist[v][1] = (dist[v][1] + dist[node][1]) % MOD;
                    // pq.push({dist[v][0], v});
                }
                if (time + wt < dist[v][0]) {
                    dist[v][0] = time + wt;
                    dist[v][1] = (dist[node][1]) % MOD;
                    pq.push({dist[v][0], v});
                }
            }
        }

        return dist[n - 1][1];
    }
};