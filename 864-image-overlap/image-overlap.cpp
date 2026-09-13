class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> A, B;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (img1[i][j] == 1)
                    A.emplace_back(i, j);
                if (img2[i][j] == 1)
                    B.emplace_back(i, j);
            }
        }
        int ans = 0;
        unordered_map<int, int> mp;
        for (auto& a : A) {
            for (auto& b : B) {
                mp[(a.first - b.first) * 1000 + a.second - b.second]++;
                ans = max(ans,
                          mp[(a.first - b.first) * 1000 + a.second - b.second]);
            }
        }
        return ans;
    }
};