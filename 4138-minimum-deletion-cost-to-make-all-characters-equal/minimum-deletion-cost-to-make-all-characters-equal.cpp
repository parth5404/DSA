class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        long long total = accumulate(cost.begin(), cost.end(), 0LL);

        unordered_map<char, long long> mp;
        for (int i = 0; i < s.length(); i++)
            mp[s[i]] += cost[i];

        long long ans = LLONG_MAX;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            ans = min(ans, total - it->second);
        }

        return ans;
    }
};