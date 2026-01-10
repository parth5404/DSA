class Solution {
public:
    vector<vector<int>> dp;
    int solve(string &s1, string &s2, int i, int j) {
        if (i == s1.length()) {
            if (j != s2.length()) {
                int sum = 0;
                while (j < s2.length()) {
                    sum += s2[j];
                    j++;
                }
                return sum;
            } else
                return 0;
        }
        if (j == s2.length()) {
            if (i != s1.length()) {
                int sum = 0;
                while (i < s1.length()) {
                    sum += s1[i];
                    i++;
                }
                return sum;
            } else
                return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int case1 = INT_MAX;
        int case2 = INT_MAX;
        int case3 = INT_MAX;
        if (s1[i] == s2[j]) {
            case1 = solve(s1, s2, i + 1, j + 1);
        } else {
            case2 = s2[j] + solve(s1, s2, i, j + 1);
            case3 = s1[i] + solve(s1, s2, i + 1, j);
        }
        return dp[i][j]=min({case1, case2, case3});
    }
    int minimumDeleteSum(string s1, string s2) {
        this->dp = vector<vector<int>>(s1.length() + 1,
                                       vector<int>(s2.length() + 1, -1));
        return solve(s1, s2, 0, 0);
    }
};