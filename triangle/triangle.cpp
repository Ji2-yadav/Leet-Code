class Solution {
public:
    int dp[201][201];
    int sum(vector<vector<int>>& triangle,int n,int i)
    {
        if(n==triangle.size())
            return 0;
        if(i<0 || i>=triangle[n].size())
            return 1e9;
        
        if(dp[n][i]!=-1)
            return dp[n][i];
        
        int s1 =  sum(triangle,n+1,i);
        int s2 =  sum(triangle,n+1,i+1);
        
        dp[n+1][i] = s1;
        dp[n+1][i+1] = s2;
        return dp[n][i] = min(triangle[n][i] +s1,triangle[n][i]+s2);

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof(dp));
        
        return sum(triangle,0,0);
    }
};