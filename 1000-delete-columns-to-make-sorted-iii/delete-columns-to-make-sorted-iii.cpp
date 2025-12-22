class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        vector<int> dp(strs[0].length(), 1);
        int ans = 0;
        for (int i = 0; i < strs[0].length(); i++) {
            for (int j = 0; j < i; j++) {
                bool valid=true;
                for(int k=0;k<strs.size();k++){
                    if(strs[k][j]>strs[k][i]){
                        valid=false;
                        break;
                    }
                }
                if(valid){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            ans=max(ans,dp[i]);
        }
        return strs[0].length()-ans;
    }
};