class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int cnt=0;
        long long mini=INT_MAX;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                long long k=abs(matrix[i][j]);
                sum = sum + k;
                if(matrix[i][j]<0){
                    cnt++;
                }
                mini=min(mini,k);
            }
        }
        if(cnt%2==1)return sum-mini-mini;
        return sum;
    }
};