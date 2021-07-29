class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> loc(101); 
        for (int i = 0; i < size(nums); ++i) 
            loc[nums[i]].push_back(i); 
        
        vector<int> ans; 
        for (auto& query : queries) {
            int prev = 0, val = INT_MAX; 
            for (int x = 1; x <= 100; ++x) {
                auto it = lower_bound(loc[x].begin(), loc[x].end(), query[0]); 
                if (it != loc[x].end() && *it <= query[1]) {
                    if (prev) val = min(val, x - prev); 
                    prev = x; 
                }
            }
            ans.push_back(val < INT_MAX ? val : -1); 
        }
        return ans; 
    }
};