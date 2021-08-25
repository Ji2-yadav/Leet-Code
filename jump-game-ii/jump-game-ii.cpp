class Solution {
public:
    int jump(vector<int>& nums) {
        int i=0,j,max_step,jump=0,max_i;
        while(i<nums.size()-1)
        {
            if(i + nums[i] >=nums.size()-1)
            {
                jump++;
                i +=nums[i];
            }
            else
            {
                max_step = i + nums[i] + nums[i+nums[i]];
                max_i = i + nums[i];
                for(j=1;j<nums[i];j++)
                {
                    if((i + j + nums[i+j]) > max_step )
                    {
                        max_step = i + j + nums[i+j];
                        max_i = i + j;
                    }
                }
                i = max_i;
                jump++;
                
            }
        }
        return jump;
    }
};