class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); 

        vector<vector<int>> ans; 
        for (int i = 0; i < nums.size(); ++i) {
            if (i && nums[i-1] == nums[i]) continue; 
            for (int j = i+1; j < nums.size(); ++j) {
                if (i+1 < j && nums[j-1] == nums[j]) continue; 
                int lo = j+1, hi = nums.size()-1; 
                while (lo < hi) {
                    int sm = nums[i] + nums[j] + nums[lo] + nums[hi]; 
                    if (sm < target || (j+1 < lo && nums[lo-1] == nums[lo])) ++lo; 
                    else if (sm > target || (hi+1 < nums.size() && nums[hi] == nums[hi+1])) --hi; 
                    else ans.push_back({nums[i], nums[j], nums[lo++], nums[hi--]}); 
                }
            }
        }
        return ans; 
    }
};