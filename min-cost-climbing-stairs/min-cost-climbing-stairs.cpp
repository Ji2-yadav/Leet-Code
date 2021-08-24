class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int sz=cost.size();
        int F[sz];
        F[sz-1] = cost[sz-1];
        F[sz-2] = cost[sz-2];
        for(int i=sz-3;i>=0;i--)
        {
            F[i] = cost[i] + min(F[i+1],F[i+2]);
        }
        return min(F[0],F[1]);
    }
};