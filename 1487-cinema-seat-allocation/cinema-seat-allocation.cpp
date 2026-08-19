class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        sort(rs.begin(), rs.end());
        int ans = 0;
        int cnt = 0;
        int prev_row = -1;
        int j = 0;
        while (j < rs.size()) {
            array<int, 3> arr = {0, 0, 0};
            while (j < rs.size() && (prev_row == -1 || prev_row == rs[j][0])) {
                if (rs[j][1] >= 2 && rs[j][1] <= 5) {
                    arr[0] = 1;
                }
                if (rs[j][1] >= 4 && rs[j][1] <= 7) {
                    arr[1] = 1;
                }
                if (rs[j][1] >= 6 && rs[j][1] <= 9) {
                    arr[2] = 1;
                }
                prev_row = rs[j][0];
                j++;
            }
            cnt++;
            prev_row = -1;
            int sum = arr[0] + arr[1] + arr[2];
            if (!arr[0] && !arr[1] && !arr[2])
                ans += 2;
            else if (sum == 1 || sum == 2)
                ans += 1;
        }
        ans += (n - cnt) * 2;
        return ans;
    }
};