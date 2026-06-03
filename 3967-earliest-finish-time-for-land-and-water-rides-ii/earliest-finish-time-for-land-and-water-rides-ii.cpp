class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws,
                           vector<int>& wd) {
        int ans = INT_MAX;
        for (int i = 0; i < ls.size(); i++) {
            ans = min(ans, ls[i] + ld[i]);
        }
        int ans1 = INT_MAX;
        int ans2 = INT_MAX;
        for (int i = 0; i < ws.size(); i++) {
            ans2 = min(ans2, ws[i] + wd[i]);
            ans1 = min(max(ans, ws[i]) + wd[i], ans1);
        }
        int ans3 = INT_MAX;
        for (int i = 0; i < ls.size(); i++) {
            ans3 = min(max(ans2, ls[i]) + ld[i], ans3);
        }
        return min(ans1,ans3);
    }
};