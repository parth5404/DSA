class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (auto it : words)
            mp[it]++;
        vector<pair<int, string>> pq;
        for (auto it : mp) {
            pq.push_back({it.second, it.first});
        }
        sort(pq.begin(), pq.end(), [](auto& a, auto& b) {
            if (a.first != b.first)
                return a.first > b.first;
            return a.second < b.second;
        });
        vector<string> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(pq[i].second);
        }

        return ans;
    }
};