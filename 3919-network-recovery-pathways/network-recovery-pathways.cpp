class Solution {
public:
    bool djs(unordered_map<int, vector<array<int, 2>>>& mp, long long k, int n,
             int mid) {
        vector<long long> dist(n, 4e18);
        dist[0] = 0;
        priority_queue<array<long long, 2>, vector<array<long long, 2>>,
                       greater<array<long long, 2>>>
            pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            if (top[0] > k) {
                return false;
            }
            if (top[1] == n - 1) {
                return true;
            }
            if (top[0] > dist[top[1]]) {
                continue;
            }
            for (auto it : mp[top[1]]) {
                if (it[1] < mid) {
                    continue;
                }
                if (dist[top[1]] + it[1] < dist[it[0]]) {
                    dist[it[0]] = dist[top[1]] + it[1];
                    pq.push({dist[it[0]], it[0]});
                }
            }
        }

        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                         long long k) {
        int n = online.size();
        unordered_map<int, vector<array<int, 2>>> mp;
        int s = INT_MAX;
        int e = 0;
        for (auto it : edges) {
            if (online[it[0]] && online[it[1]]) {
                mp[it[0]].push_back({it[1], it[2]});
                s = min(s, it[2]);
                e = max(e, it[2]);
            }
        }

        int ans = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (djs(mp, k, n, mid)) {
                s = mid + 1;
                ans = mid;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }
};