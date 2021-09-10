class Solution {
public:
    int getMaxLen(vector<int>& nums) {
         int n=nums.size();
    
    int neg=0,pos=0;
    
    int maxLen=0;
    
    for(int i=0;i<n;i++){
        
        if(nums[i]==0){
            neg=0,pos=0;
            continue;
        }
        
        else if(nums[i]>0){
            
            pos++;
            
            if(neg!=0){
                neg++;
            }
            
            maxLen=max(maxLen,pos);
            
        }
        
       else if(nums[i]<0){
           
           swap(pos,neg);
           
           neg++;
           
           if(pos!=0){
               pos++;
           }
           
           maxLen=max(maxLen,pos);
           
       }
        
    }
    
    return maxLen;   
    }
};