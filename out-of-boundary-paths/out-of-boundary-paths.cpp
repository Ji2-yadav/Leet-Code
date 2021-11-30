class Solution {
public:
    int dp[52][52][52];
    unsigned int mod =  1000000007;
    int paths(int m, int n, int maxMove, int sR, int sC, int CurrMove)
    {
        if(sR<0 || sC <0 || sR>=m || sC>=n)
        {
            if(CurrMove<=maxMove)
                return 1;
        }
        if(CurrMove>maxMove)
            return 0;
        
        if(dp[sR][sC][CurrMove]!=-1)
            return dp[sR][sC][CurrMove];
        
        int left = paths(m,n,maxMove,sR-1,sC,CurrMove+1) % mod;
        int right = paths(m,n,maxMove,sR+1,sC,CurrMove+1)% mod;
        int up = paths(m,n,maxMove,sR,sC-1,CurrMove+1)% mod;
        int down = paths(m,n,maxMove,sR,sC+1,CurrMove+1)% mod;
        
        return dp[sR][sC][CurrMove] = ( (left + right) % mod + (up + down)% mod )% mod ;
    }
    
    int findPaths(int m, int n, int maxMove, int sR, int sC) {
        memset(dp,-1,sizeof(dp));
        return paths(m,n,maxMove,sR,sC,0);
    }
};