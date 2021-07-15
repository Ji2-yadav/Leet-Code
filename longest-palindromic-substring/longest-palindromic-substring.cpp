class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.size();
        int dp[n][n];
        int len = 1;
        int left = 0;
       
        for(int i = n-1;i>=0;--i){
            for(int j = i;j<n;++j){
        
                if(i == j){
                   dp[i][j]=1; 
                }
              
                else if(j==i+1){
                    if(s[i]==s[j]){
                        dp[i][j]=2;
                    }
                    else{
                        dp[i][j]=-1;
                  }
                }
                else{
                    if(dp[i+1][j-1] != -1 && s[i]==s[j]){
                        dp[i][j]=dp[i+1][j-1]+2;
                    }
                    else{
                        dp[i][j]=-1;
                    }
                }
                
                if(dp[i][j]>=len){
                    len = dp[i][j];
                    left = i;
                }
            }
        }
        return s.substr(left,len);
    }
};
