class Solution {
public:
    int arr[101][101];
    
    int sum(vector<vector<int>>& matrix,int x,int y)
    {
        if(x>=matrix.size())
            return 0;
        if(y<0 || y>=matrix[0].size())
            return 10e7;
        
        if(arr[x][y]!=-1)
            return arr[x][y];
        
        int ch1 = matrix[x][y]+ sum(matrix,x+1,y-1);
        int ch2 = matrix[x][y]+ sum(matrix,x+1,y);
        int ch3 = matrix[x][y]+ sum(matrix,x+1,y+1);
        
        return arr[x][y]=min(ch1,min(ch2,ch3));        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mn = INT_MAX;
        int temp;
        memset(arr,-1,sizeof(arr));
        for(int i=0;i<matrix[0].size();i++)
        {
            temp = sum(matrix,0,i);
            mn = min(mn,temp);
        }
        return mn;
            
    }
};