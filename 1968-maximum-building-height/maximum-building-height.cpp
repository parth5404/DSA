class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) { return a[0] < b[0]; }
    int maxBuilding(int n, vector<vector<int>>& rest) {
        rest.push_back({1, 0});
        sort(rest.begin(), rest.end(), cmp);
        int m = rest.size();
        // Left -> Right
        for (int i = 1; i < m; i++) {
            int dist = rest[i][0] - rest[i - 1][0];
            rest[i][1] = min(rest[i][1], rest[i - 1][1] + dist);
        }
        // Right -> Left
        for (int i = m - 2; i >= 0; i--) {
            int dist = rest[i + 1][0] - rest[i][0];
            rest[i][1] = min(rest[i][1], rest[i + 1][1] + dist);
        }
        int max_ht = 0;
        int prev_id = rest[0][0];
        int prev_ht = rest[0][1];
        for (int i = 1; i < rest.size(); i++) {
            int id = rest[i][0];
            int ht = rest[i][1];
            int d = id - prev_id;
            if (d >= 1) {
                max_ht = max(max_ht, (d + prev_ht + ht) / 2);
            }
            prev_id = id;
            prev_ht = ht;
        }
        max_ht = max(max_ht, (prev_ht + (n - prev_id)));
        return max_ht;
    }
};