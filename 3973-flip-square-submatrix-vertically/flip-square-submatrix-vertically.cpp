class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int lstx=x+k-1;
        int lsty=y+k-1;
        while(x<=lstx){
            for(int i=y;i<=lsty;i++){
                swap(grid[x][i],grid[lstx][i]);
            }
            x++;
            lstx--;
        }
        return grid;
    }
};