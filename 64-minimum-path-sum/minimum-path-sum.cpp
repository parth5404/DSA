class Solution {
public:
vector<vector<int>>dp;
int dfs(vector<vector<int>>& grid,int i,int j){
    if(i>=grid.size() || j>=grid[0].size())return INT_MAX;
    if(i==grid.size()-1 && j==grid[0].size()-1){
        return grid[i][j];
    }
    if(dp[i][j]!=-1)return dp[i][j];
    return dp[i][j]=grid[i][j]+min(dfs(grid,i+1,j),dfs(grid,i,j+1));
}
    int minPathSum(vector<vector<int>>& grid) {
        this->dp=vector<vector<int>>(grid.size()+1,vector<int>(grid[0].size()+1,-1));
        return dfs(grid,0,0);
    }
};