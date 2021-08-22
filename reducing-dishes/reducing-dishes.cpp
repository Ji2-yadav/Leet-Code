class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) 
    {
        int n=satisfaction.size();
        int max=0;
        sort(satisfaction.begin(),satisfaction.end());
        for(int i=0;i<n-1;i++)
        {
            int sum=0;
            int k=1;
            for(int j=i;j<n;j++)
            {
                sum=sum+ k*(satisfaction[j]);
                k++;
            }
            k=1;
            if(sum>max)
                max=sum;
        }
        return max;
        
    }
};