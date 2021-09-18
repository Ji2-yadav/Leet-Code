class Solution {
public:
    unordered_map<int,int> mp;
    int fun(int n)
    {
        if(n<=0)
            return 0;
        if(n==1)
            return 1;
        
        if(mp.find(n)!=mp.end())
            return mp[n];
    
        
            int n2 = fun(n/2);
            int n3 = fun(n/3);
        
        return mp[n] = min(1+n%2+n2,1+n%3+n3);
    }
    int minDays(int n) {
        return fun(n);
    }
};