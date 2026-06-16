class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) { return a[1] < b[1]; }
    int findMinArrowShots(vector<vector<int>>& pts) {
        sort(pts.begin(), pts.end(), cmp);
        long long mini = pts[0][0];
        long long maxi = pts[0][1];
        int ans = 1;
        for (int i = 1; i < pts.size(); i++) {
            int x1 = pts[i][0];
            int x2 = pts[i][1];
            if (x1 > maxi) {
                ans++;
                mini = x1;
                maxi = x2;
            } else {
                mini = max(mini, x1 * 1LL);
                maxi = min(maxi, x2 * 1LL);
            }
        }
        return ans;
    }
};