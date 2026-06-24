class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<array<int, 2>>> mp;
        for (auto it : times) {
            mp[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        priority_queue<array<int, 2>, vector<array<int, 2>>,
                       greater<array<int, 2>>>
            pq;
        pq.push({0, k});
        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();
            if (time > dist[node])
                continue;
            for (auto [v, wt] : mp[node]) {
                if (time + wt < dist[v]) {
                    dist[v] = time + wt;
                    pq.push({time + wt, v});
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 1; i < dist.size(); i++) {
            if (dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};