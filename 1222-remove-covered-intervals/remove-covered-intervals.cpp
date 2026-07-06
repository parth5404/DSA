class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] != b[0])
            return a[0] < b[0];
        else {
            return a[1] > b[1];
        }
    }
    int removeCoveredIntervals(vector<vector<int>>& it) {
        sort(it.begin(), it.end(), cmp);
        int maxs = it[0][0];
        int maxe = it[0][1];
        int ans = it.size();
        for (int i = 1; i < it.size(); i++) {
            cout << maxs << " " << maxe << endl;
            if (it[i][1] <= maxe) {
                ans--;
            } else {
                maxe = it[i][1];
            }
        }
        return ans;
    }
};