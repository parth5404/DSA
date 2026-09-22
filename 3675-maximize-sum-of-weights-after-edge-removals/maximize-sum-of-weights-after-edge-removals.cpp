class Solution {
public:
    unordered_map<int, vector<array<int, 2>>> mp;
    int k;
    pair<long long, long long> solve(int node, int parent) {
        vector<pair<long long, long long>> ch;
        for (auto& [child, w] : mp[node]) {
            if (child == parent)
                continue;
            auto [keepC, cutC] = solve(child, node);
            ch.push_back({w + keepC, cutC});
        }
        sort(ch.begin(), ch.end(), [](auto& a, auto& b) {
            return a.first - a.second > b.first - b.second;
        });
        auto total = [&](int limit) {
            long long sum = 0;
            int taken = 0;
            for (auto& [chuna, nahiChuna] : ch) {
                if (taken < limit && chuna - nahiChuna > 0) {
                    sum += chuna;
                    taken++;
                } else {
                    sum += nahiChuna;
                }
            }
            return sum;
        };

        return {total(k - 1), total(k)}; // {keep, cut}
    }
    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        for (auto& e : edges) {
            mp[e[0]].push_back({e[1], e[2]});
            mp[e[1]].push_back({e[0], e[2]});
        }
        this->k = k;
        return solve(0, -1).second;
    }
};