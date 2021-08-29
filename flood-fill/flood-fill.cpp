class Solution {
public:
    int dp[51][51];
    void fill(vector<vector<int>>& image, int i,int j, int col, int newcol)
    {
        if(i<0 || i>=image.size() || j<0 || j>=image[0].size())
            return;
        
        if(col==newcol)
        {
            dp[i][j] = 0;
            return;
        }
        if(dp[i][j]!=-1)
            return;
        if(image[i][j] == col)
        { 
            image[i][j] = newcol;
            
            fill(image,i+1,j,col,newcol);
            fill(image,i-1,j,col,newcol);
            fill(image,i,j+1,col,newcol);
            fill(image,i,j-1,col,newcol);
        }
        
        dp[i][j] = 0;
        
        return ;
        
        
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        memset(dp,-1,sizeof(dp));
        
        fill(image,sr,sc,image[sr][sc],newColor);
        
        return image;
        
        
    }
};