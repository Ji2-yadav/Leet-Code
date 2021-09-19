class Solution {
public:
     int count(vector<int>&nums,int mid)
    {
        int i=0,j=0,c=0;
        for(i=0;i<nums.size();i++)
        {
            while(j<nums.size()&&nums[j]-nums[i]<=mid)
            {
                j++;
            }
            c=c+j-i-1;
        }
        return c;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0,r=1000000,ans=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(count(nums,mid)>=k)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};