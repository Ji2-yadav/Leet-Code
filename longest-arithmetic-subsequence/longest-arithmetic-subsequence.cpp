class Solution {
public:
    int longestArithSeqLength(vector<int>& v) {
        int n=v.size();
        vector<vector<int>> dp(1001, vector<int>(n+1,1));
        int ans=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
			// add 500 to difference because difference can also be negative so make it >= 0
                int d = v[i]-v[j] + 500;
				
				// add 1 to dp[d][j] which is answer till j with same d (difference)
                dp[d][i] = dp[d][j]+1;
				// take maximum
                ans = max(ans,dp[d][i]);
            }
        }
        return ans;
    }
};