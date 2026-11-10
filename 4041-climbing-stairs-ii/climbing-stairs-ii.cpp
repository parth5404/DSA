class Solution {
public:
unordered_map<int,int>mp;
    int solve(int n, vector<int>& costs, int i) {
        if (i >= n - 1) {
            return 0;
        }
        if(mp.count(i)){
            return mp[i];
        }
        int ans = INT_MAX;
        if (i + 1 <= n - 1) {
            ans = min(ans, costs[i + 1] + (i + 1 - i) * (i + 1 - i) +
                               solve(n, costs, i + 1));
        }
        if (i + 2 <= n - 1) {
            ans = min(ans, costs[i + 2] + (i + 2 - i) * (i + 2 - i) +
                               solve(n, costs, i + 2));
        }
        if (i + 3 <= n - 1) {
            ans = min(ans, costs[i + 3] + (i + 3 - i) * (i + 3 - i) +
                               solve(n, costs, i + 3));
        }
        return mp[i]=ans;
    }
    int climbStairs(int n, vector<int>& costs) { return solve(n, costs, -1); }
};