class Solution {
public:
    set<pair<int,int>> s;
    int checkedrow[251];
    int checkedcol[251];

    void check(vector<vector<int>>& grid,int i,int j)
    {
        int cnt = 0;
         if(checkedcol[j]!=1)
        {
           for(int row =0;row<grid.size();row++)
            {
                if(grid[row][j]==1 && row!=i)
                {
                    s.insert(make_pair(row,j));
                    cnt++;
                }
            } 
            checkedcol[j] = 1;

        }
        
         if(checkedrow[i]!=1)
        {
            for(int col =0;col<grid[0].size();col++)
            {
                if(grid[i][col]==1 && col!=j)
                {
                    s.insert(make_pair(i,col));
                    cnt++;
                }
            }
           checkedrow[i] = 1;
        }
        
        if(cnt!=0)
            s.insert(make_pair(i,j));
        
        return;
    }
    int countServers(vector<vector<int>>& grid) {
        memset(checkedrow,0,sizeof(checkedrow));
        memset(checkedcol,0,sizeof(checkedcol));
        
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j]!=0)
                    check(grid,i,j);
        
        return s.size();
    }
};