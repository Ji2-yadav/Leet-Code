class Solution {
public:
    int dp[201][201];
    int fun(vector<vector<int>>& grid,int i,int j)
    {
        if(i<0 || i> grid.size()-1 || j<0 || j> grid[0].size()-1)
            return 1e8;
        if(i==grid.size()-1 && j==grid[0].size()-1)
            return grid[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int right =  fun(grid,i+1,j);
        int down =   fun(grid,i,j+1);
        dp[i+1][j] = right;
        dp[i][j+1] = down;
        
        
        return dp[i][j] = min(grid[i][j] + right,grid[i][j] + down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        
        return fun(grid,0,0);
    }
};