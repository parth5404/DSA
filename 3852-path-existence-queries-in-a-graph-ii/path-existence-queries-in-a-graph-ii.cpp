class Solution {
public:
    static const int LOG = 18;
    int up[LOG][100005];
    int getJumps(int u, int v) {
        if (u == v)
            return 0;
        if (up[0][u] >= v)
            return 1;
        if (up[LOG - 1][u] < v)
            return -1;
        int jumps = 0;
        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][u] < v) {
                jumps += (1 << j);
                u = up[j][u];
            }
        }
        return jumps + 1;
    }
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {
        vector<array<int, 2>> vec;
        for (int i = 0; i < nums.size(); i++) {
            vec.push_back({nums[i], i});
        }
        sort(vec.begin(), vec.end());
        vector<int> pos(n, 0);
        for (int i = 0; i < n; i++) {
            pos[vec[i][1]] = i;
        }
        int left = 0;
        for (int right = 0; right < vec.size(); right++) {
            while (left + 1 < vec.size() &&
                   abs(vec[right][0] - vec[left + 1][0]) <= maxDiff) {
                left++;
            }
            up[0][right] = left;
        }
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                up[j][i] = up[j - 1][up[j - 1][i]];
            }
        }
        vector<int> ans;
        for (auto& q : queries) {
            int u = pos[q[0]];
            int v = pos[q[1]];

            if (u > v)
                swap(u, v);

            ans.push_back(getJumps(u, v));
        }
        return ans;
    }
};