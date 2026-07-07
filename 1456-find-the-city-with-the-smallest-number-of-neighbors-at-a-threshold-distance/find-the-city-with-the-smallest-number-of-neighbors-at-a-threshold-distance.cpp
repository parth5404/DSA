class Solution {
public:
    unordered_map<int, vector<array<int, 2>>> mp;
    int djs(int n, int k, int src) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq;
        pq.push({0, src});
        while (!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();
            if (wt > dist[node])
                continue;
            for (auto [v, wt1] : mp[node]) {
                if (wt1 + wt > k)
                    continue;
                if (wt1 + wt < dist[v]) {
                    dist[v] = wt1 + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < dist.size(); i++) {
            if (dist[i] <= k && i != src)
                cnt++;
        }
        return cnt;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        for (auto it : edges) {
            mp[it[0]].push_back({it[1], it[2]});
            mp[it[1]].push_back({it[0], it[2]});
        }
        int ans = INT_MAX;
        int ret_ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (ans >= djs(n, k, i)) {
                ans = djs(n, k, i);
                ret_ans = i;
            }
        }
        return ret_ans;
    }
};