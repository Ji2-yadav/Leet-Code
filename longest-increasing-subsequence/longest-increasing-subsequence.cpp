class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
          
       int n= a.size();
       int dp[n];
       dp[0]=1;
       int lis = dp[0];
       for(int i=1;i<n;i++){
           int var =0;
           for(int j=0;j<i;j++){
               if(a[j] < a[i])
                    var= max(var,dp[j]);
           }
           dp[i]=var+1;
           lis=max(lis,dp[i]);
       }
       return lis;
    }
};