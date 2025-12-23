class Solution {
public:
vector<vector<int>> dp;
    int bs(vector<vector<int>> &events, int &key, int &idx) {
        int s = idx + 1;
        int e = events.size() - 1;
        int ans = events.size();
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (events[mid][0] > key) {
                ans = mid;
                e = mid - 1;
            } else
                s = mid + 1;
        }
        // if (e == events.size())
        //     return -1;
        return ans;
    }
    int solve(vector<vector<int>>& events, int idx, int cnt) {
        if (idx == events.size() || cnt == 2) {
            return 0;
        }
        if(dp[idx][cnt]!=-1)return dp[idx][cnt];
        int new_idx = bs(events, events[idx][1], idx);
        // int include = INT_MIN;
        // if (new_idx != -1)
        int include = events[idx][2] + solve(events, new_idx, cnt + 1);
        int exclude = solve(events, idx + 1, cnt);
        return dp[idx][cnt]=max(include, exclude);
    }
    static bool comp(vector<int> &a, vector<int> &b) { return a[0] < b[0]; }
    int maxTwoEvents(vector<vector<int>>& events) {
        this->dp=vector<vector<int>>(100001,vector<int>(4,-1));
        sort(events.begin(), events.end(), comp);
        return solve(events, 0, 0);
    }
};