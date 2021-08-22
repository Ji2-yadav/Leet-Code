class Solution {
public:
    int dp[50][50][50];
    int solution(int r1,int c1,int r2,int n,vector<vector<int>>& grid){
        int c2=r1+c1-r2;
        if(r1>=n or r2>=n or c1>=n or c2>=n or grid[r1][c1]==-1 or grid[r2][c2]==-1){
            return INT_MIN;
        }
        if(dp[r1][c1][r2]!=-1){
            return dp[r1][c1][r2];
        }
        
        if(r1==n-1 and c1==n-1){
            return grid[r1][c1];
        }
        

        int cheries=0;
        if(r2==r1 and c1==c2){
            cheries+=grid[r1][c1];
        }else{
            cheries+=grid[r1][c1]+grid[r2][c2];
        }
        
        int f1=solution(r1,c1+1,r2,n,grid);//hh
        int f2=solution(r1,c1+1,r2+1,n,grid);//hv
        int f3=solution(r1+1,c1,r2,n,grid);//vh
        int f4=solution(r1+1,c1,r2+1,n,grid);//vv
        cheries+=max(max(f1,f2),max(f3,f4));
        dp[r1][c1][r2]=cheries;
        return cheries;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        
        memset(dp,-1,sizeof(dp));
        
        return max(0,solution(0,0,0,n,grid));
    }
};