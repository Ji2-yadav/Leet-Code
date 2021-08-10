class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) 
    {
        if(s.back() == '1')
            return false;
        
        vector<bool> dp(s.size(), false);
        dp[0] = true;
        
        int count = 0;
        for(int i = 1; i < s.size(); ++i)
        {
            count += i >= minJump ? dp[i-minJump] : 0;
            count -= i > maxJump ? dp[i-maxJump-1] : 0;
            
            if(count > 0 && s[i] == '0')
                dp[i] = true;
        }
        if(dp.back())
            return true;
        return false;
    }
};