class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int cnt = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                bool flag = false;
                if (mat[i][j] == 1) {
                    for (int k = 0; k < mat[i].size(); k++) {
                        if (mat[i][k] == 1 && k != j) {
                            flag = true;
                            break;
                        }
                    }
                    for (int k = 0; k < mat.size(); k++) {
                        if (mat[k][j] == 1 && k != i) {
                            flag = true;
                            break;
                        }
                    }
                    if (!flag) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};