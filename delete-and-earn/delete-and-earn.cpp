class Solution {
public:
    int deleteAndEarn(vector<int>& nums) { vector<int>v (10005,0);
    
    
       int n=nums.size();
    int dp[10005];
    for(int i=0;i<n;i++)
    {
        v[nums[i]]+=nums[i];
    }
    dp[0]=0;
    dp[1]=v[1];
    dp[2]=max(v[1],v[2]);
    for(int i=3;i<10005;i++)
    {
        dp[i]=max(dp[i-2]+v[i],dp[i-1]);
    }
    return max(dp[1004],dp[1003]);
    }
        
    
};