class Solution {
public:
    int rob(vector<int>& nums) {
         int n = nums.size();
        if(n == 1)
            return nums[0];
        if(n == 2)
            return max(nums[0], nums[1]);
        vector<int> rob1(n);
        vector<int> rob2(n);
        
        rob1[0] = nums[0];
        rob1[1] = max(nums[0], nums[1]);
        
        for(int i = 2; i<n-1; i++) {
            rob1[i] = max(rob1[i - 2] + nums[i], rob1[i - 1]);
        }
        
        rob2[0]= 0;
        rob2[1] = nums[1];
        rob2[2] = max(nums[1], nums[2]);
        for(int i = 3; i<n; i++) {
            rob2[i] = max(rob2[i - 2] + nums[i], rob2[i - 1]);
        }
        
        return max(rob1[n-2], rob2[n-1]);
    }
};