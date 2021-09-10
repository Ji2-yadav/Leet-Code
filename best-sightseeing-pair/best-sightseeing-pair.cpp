class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& v) {
        int n = v.size();
        int curr = v[0] + 0;
        int ans = INT_MIN;
        for(int j=1;j<n;j++){
            ans = max(ans,curr+v[j]-j);
            curr = max(curr,v[j]+j);
        }
        return ans;
    }
};