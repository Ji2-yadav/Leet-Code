class Solution {
public:
    void rotate(vector<int>& nums, int k) {
         k=k%nums.size(); //if k is greator than size it will make it into range.
        vector<int>out;
        for(int i=nums.size()-k;i<nums.size();i++)
        {
            out.push_back(nums[i]);
        }
        for(int i=0;i<nums.size()-k;i++)
        {
            out.push_back(nums[i]);
        }
        swap(nums,out); 
    }
};