class Solution {
public:
    set<int> st;
    unordered_map<string, vector<pair<string, long long>>> mp;
    typedef pair<long long, string> P;
    vector<long long> dp;

    long long dijkstra(string src, string dest) {
        priority_queue<P, vector<P>, greater<P>> pq;
        unordered_map<string, long long> dist;

        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty()) {
            auto [curr_c, u] = pq.top();
            pq.pop();

            if (u == dest) return curr_c;

            if (curr_c > dist[u]) continue;

            for (auto &nei : mp[u]) {
                string v = nei.first;
                long long w = nei.second;

                if (!dist.count(v) || curr_c + w < dist[v]) {
                    dist[v] = curr_c + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return 1e10;
    }

    long long solve(int i, string &src, string &target) {
        if (i == src.size() && i == target.size()) return 0;
        if (i >= src.size() || i >= target.size()) return 1e10;

        if (dp[i] != -1) return dp[i];

        long long ans = 1e10;

        for (int len : st) {
            if (i + len > src.size() || i + len > target.size()) break;

            string s1 = src.substr(i, len);
            string s2 = target.substr(i, len);

            if (!mp.count(s1)) continue;

            long long cost = dijkstra(s1, s2);
            if (cost < 1e10) {
                ans = min(ans, cost + solve(i + len, src, target));
            }
        }

        if (src[i] == target[i]) {
            ans = min(ans, solve(i + 1, src, target));
        }

        return dp[i] = ans;
    }

    long long minimumCost(string source, string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {

        for (auto &s : original) st.insert(s.length());

        for (int i = 0; i < original.size(); i++) {
            mp[original[i]].push_back({changed[i], cost[i]});
        }

        dp.assign(source.size() + 1, -1);

        long long ans = solve(0, source, target);
        return ans >= 1e10 ? -1 : ans;
    }
};
