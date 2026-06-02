class Solution {
public:
    int solve(vector<int>& ls, vector<int>& ld, vector<int>& ws,
              vector<int>& wd) {
        int ans = INT_MAX;
        for (int i = 0; i < ls.size(); i++) {
            ans = min(ans, ls[i] + ld[i]);
        }
        int ans1 = INT_MAX;
        for (int i = 0; i < ws.size(); i++) {
            ans1 = min(max(ans, ws[i]) + wd[i], ans1);
        }
        return ans1;
    }
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws,
                           vector<int>& wd) {
        int ans = INT_MAX;
        for (int i = 0; i < ws.size(); i++) {
            ans = min(ans, wd[i] + ws[i]);
        }
        int ans1 = INT_MAX;
        for (int i = 0; i < ls.size(); i++) {
            ans1 = min(max(ans, ls[i]) + ld[i], ans1);
        }
        return min(ans1,solve(ls,ld,ws,wd));
    }
};