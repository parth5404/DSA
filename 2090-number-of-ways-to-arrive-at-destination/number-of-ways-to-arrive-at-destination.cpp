class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<array<int, 2>>> mp;
        for (auto it : roads) {
            mp[it[0]].push_back({it[1], it[2]});
            mp[it[1]].push_back({it[0], it[2]});
        }
        vector<array<long long, 2>> dist(n, {LLONG_MAX, 0});
        dist[0] = {0, 1};
        priority_queue<array<long long, 3>, vector<array<long long, 3>>,
                       greater<array<long long, 3>>>
            pq;
        pq.push({0, 0, 1});
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            if (top[0] > dist[top[1]][0])
                continue;
            for (auto it : mp[top[1]]) {
                if (top[0] + it[1] < dist[it[0]][0]) {
                    dist[it[0]][0] = top[0] + it[1];
                    dist[it[0]][1] = dist[top[1]][1];
                    pq.push({dist[it[0]][0], it[0], top[2]});
                } else if (top[0] + it[1] == dist[it[0]][0]) {
                    dist[it[0]][1] =
                        (dist[it[0]][1] + dist[top[1]][1]) % (int)(1e9 + 7);
                }
            }
        }
        return dist[n - 1][1];
    }
};