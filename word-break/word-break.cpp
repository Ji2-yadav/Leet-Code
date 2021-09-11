class Solution {
public:
    int solve(string s, vector<string>& dict,
                    unordered_map<string,int> &dp,map<string,int> &mp){
        int n = s.size();
        if(n==0) return dp[s]=1;
        if(dp[s]!=0) return dp[s];
        for(int i=1;i<=n;i++)
        {
            string ss = s.substr(0,i);
            if(mp[ss]==1 && solve(s.substr(i,n-i),dict,dp,mp)==1) 
                return dp[s]=1;
        }
        return dp[s]=-1;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> dp;
        map<string,int> mp;
        for(auto str:wordDict){
            mp[str]=1;
        }
        if(solve(s,wordDict,dp,mp)==1)
            return true;
        else return false;
    }
};