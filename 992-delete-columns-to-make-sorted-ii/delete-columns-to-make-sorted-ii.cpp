class Solution {
public:
    bool remidx(vector<string> strs, int idx) {
        for (int i = 0; i < strs.size(); i++) {
            if (idx < strs[i].size()) {
                strs[i].erase(idx, 1);
            }
        }
        for (int i = 1; i < strs.size(); i++) {
            if (strs[i] < strs[i - 1])
                return false;
        }
        return true;
    }
    bool checklex(vector<string> strs) {
        for (int i = 1; i < strs.size(); i++) {
            if (strs[i] < strs[i - 1])
                return false;
        }
        return true;
    }
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        vector<bool> done(strs.size(), 0);
        for (int i = 0; i < strs[0].length(); i++) {
            bool voilate = 0;
            for (int j = 0; j < strs.size() - 1; j++) {
                if (done[j])
                    continue;
                else if (strs[j][i] > strs[j + 1][i]) {
                    voilate = 1;
                    break;
                }
            }
            if (voilate) {
                ans++;
                continue;
            }
            for(int k=0;k<strs.size()-1;k++){
                if(!done[k] && strs[k][i]<strs[k+1][i])done[k]=1;
            }
        }
        return ans;
    }
};