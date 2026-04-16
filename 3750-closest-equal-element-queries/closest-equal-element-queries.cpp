class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            int q = queries[i];
            auto& vec = mp[nums[q]];
            if (vec.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int pos = lower_bound(vec.begin(), vec.end(), q) - vec.begin();

            int leftIdx = vec[(pos - 1 + vec.size()) % vec.size()];
            int rightIdx = vec[(pos + 1) % vec.size()];

            int d1 = abs(q - leftIdx);
            int d2 = abs(q - rightIdx);

            d1 = min(d1, n - d1);
            d2 = min(d2, n - d2);

            ans.push_back(min(d1, d2));
        }
        return ans;
    }
};