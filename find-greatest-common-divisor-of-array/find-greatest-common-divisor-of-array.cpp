class Solution {
public:
    int findGCD(vector<int>& a) {
        int n=a.size();
        int maxe=INT_MIN,mine=INT_MAX;
        for(int i=0;i<n;i++)
        {
            maxe=max(maxe,a[i]);
        }
        for(int i=0;i<n;i++)
        {
            mine=min(mine,a[i]);
        }
        int p =__gcd(mine,maxe);
        return p;
    }
};