class Solution {
public:
    int dp[71][71][71];
    int solution(int r,int c1,int c2,int n,vector<vector<int>>& grid){
        if(r>=n or c1>=grid[0].size() or c2>=grid[0].size() or c1<0 or c2<0){
            return INT_MIN;
        }
        if(dp[r][c1][c2]!=-1){
            return dp[r][c1][c2];
        }
        if(r==n-1){
            if(c1==c2)
                return grid[r][c1];
            else
                return grid[r][c1] + grid[r][c2]; 
        }
        
        int cheries=0;
        if(c2==c1){
            cheries+=grid[r][c1];
        }else{
            cheries+=grid[r][c1]+grid[r][c2];
        }
        
        int f1=solution(r+1,c1-1,c2-1,n,grid);
        int f2=solution(r+1,c1-1,c2  ,n,grid);
        int f3=solution(r+1,c1-1,c2+1,n,grid);
        
        int f4=solution(r+1,c1,c2-1,n,grid);
        int f5=solution(r+1,c1,c2  ,n,grid);
        int f6=solution(r+1,c1,c2+1,n,grid);
        
        int f7=solution(r+1,c1+1,c2-1,n,grid);
        int f8=solution(r+1,c1+1,c2  ,n,grid);
        int f9=solution(r+1,c1+1,c2+1,n,grid);
      
        cheries += max(max(max(max(f1,f2),max(f3,f4)),max(max(f5,f6),max(f7,f8))),f9);
        dp[r][c1][c2]=cheries;
        return cheries;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        
        memset(dp,-1,sizeof(dp));
        
        return max(0,solution(0,0,grid[0].size()-1,n,grid));
    }
};