class Solution {
public:
    void dfs(int x,int y,vector<vector<int>>& grid,bool visited[][501],int &count,int row,int col)
    {
        if(x<0 or y<0 or x>=row or y>=col)return;
        if(grid[x][y]==0)return;
        if(visited[x][y]==false)
        {
            count++;
            visited[x][y]=true;
            dfs(x,y-1,grid,visited,count,row,col);
            
            dfs(x-1,y,grid,visited,count,row,col);
            
            dfs(x,y+1,grid,visited,count,row,col);
            
            dfs(x+1,y,grid,visited,count,row,col);
            
        }
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // Code here
        int row=grid.size();
        int col=grid[0].size();
        bool visited[501][501]={false};
        int ans=0,count;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1 and visited[i][j]==false)
                {
                    count=0;
                    dfs(i,j,grid,visited,count,row,col);
                    if(ans<count)
                    {
                        ans=count;
                    }
                }
            }
        }
        return ans;
    }
};