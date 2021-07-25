class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        vector<int>ta;
        vector<int>pc;
        for(int i:nums){
            sum+=i;
            if(i%3 == 1){
                ta.push_back(i);
            }
            else if(i%3 == 2){
                pc.push_back(i);
            }
        }
        sort(ta.begin(),ta.end());
        sort(pc.begin(),pc.end());
        if(sum%3 == 0){
            return sum;
        }
        else if(sum%3 == 1){
            if(pc.size()>=2)
                return max(sum-ta[0],sum-pc[0]-pc[1]);
            return sum-ta[0];
        }
        if(ta.size()>=2)
            return max(sum-pc[0],sum-ta[0]-ta[1]);
        return sum-pc[0];
    }
};