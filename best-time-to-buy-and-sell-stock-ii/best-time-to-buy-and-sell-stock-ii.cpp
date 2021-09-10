class Solution {
public:
    int maxProfit(vector<int>& prices){
        int sum=0,i,low;
        bool sold=true;
        
        if(prices.size()<=1)
            return 0;
        if(prices.size()==2)
        {
            if(prices[1]>prices[0])
                return prices[1]-prices[0];
            else
                return 0;
        }
        for(i=0;i+1<prices.size();i++)
        {
            if(prices[i]>prices[i+1] && !sold)
            {
                sum+=prices[i]-low;
                sold=true;
            }
            else if(sold)
            {
                if(prices[i]<prices[i+1])
                {
                    low=prices[i];
                    sold = false;
                }

            }
        }
        if(sold==false)
        {
            sum+=prices[prices.size()-1]-low;
        }
        return sum;
            
        
    }
};