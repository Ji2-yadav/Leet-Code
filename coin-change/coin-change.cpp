class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp (coins.size()+1,vector<int> (amount+1,INT_MAX-1));
        
        for(int j=1;j<amount+1;j++)
            if(j%coins[0]==0)
                dp[1][j] = j/coins[0];
            else
                dp[1][j] = INT_MAX - 1;
        
        for(int i=1;i<dp.size();i++)
            dp[i][0] = 0;
        for(int i=1;i<dp.size();i++)
            for(int j=1;j<dp[i].size();j++)
            {
                if(coins[i-1]<=j)
                    dp[i][j] = min(dp[i][j-coins[i-1]] + 1, dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        if(dp[dp.size()-1][dp[0].size()-1]>INT_MAX - 4 )
            return -1;
        else
        return dp[dp.size()-1][dp[0].size()-1];
    }
};