class Solution {
public:
    int ans =0;
    
    int combinationSum4(vector<int>& nums, int tar) {
       if(nums.size() == 0 ) return 0;
        
        vector<unsigned int> dp(tar+1, 0);
        dp[0] = 1;
        
        for(int i=1;i<tar+1;i++) {
            for(auto num : nums) {
                if(i - num >= 0 )
                    dp[i] = dp[i] + dp[i-num];
                }
        }
		// DP Approach
        return dp[tar];
        
        // BackTracking
        return backtrack(nums, tar, 0);
    }
 
    
    int backtrack(vector<int> nums, int tar, int index) {
      
        if(index >= nums.size()) return 0;
        if(tar == 0) return 1;
        
        int ans =0;
        
        for(int i= 0; i<nums.size(); i++) {
            if(tar - nums[i] >= 0) {
                tar -= nums[i];
            
              ans += backtrack(nums, tar, i);
            
              tar += nums[i];
            }
        }
        
        return ans;
        
    }
};