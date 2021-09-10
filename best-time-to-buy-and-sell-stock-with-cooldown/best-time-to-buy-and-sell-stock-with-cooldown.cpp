class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int b=-prices[0];
        int s=INT_MIN;
        int r=0;
        for(int i=1;i<n;i++){
            int pb=b;
            int ps=s;
            int pr=r;
            b=max(pb,pr-prices[i]);
            s=max(ps,pb+prices[i]);
            r=max(pr,ps);
        }
        return max({b,s,r});
    }
};