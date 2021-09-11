class Solution {
public:
    int integerBreak(int n) {
        int dp[n+1];
        dp[1]=1;
        dp[2]=1;
        if(n==2){
            return 1;
        }
        for(int num=3;num<=n;num++){
            int res=INT_MIN;
            for(int i=1;i<num;i++){
                res=max(res,max(i*(num-i),max(dp[i]*dp[num-i],dp[i]*(num-i))));
            }
            dp[num]=res;
        }
        return dp[n];
    }
};