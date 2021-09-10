class Solution {
public:
    int maxProfit(vector<int>& prices) {    
        if(prices.empty())
        {
            return 0;
        }

        int max=0, min=prices[0];

        for (int i = 0; i<prices.size(); i++) {
            if (prices[i] < min)
                min = prices[i]; 
                //This pass helps us ascertain the minimum stock price
            else if (prices[i] - min > max)
                max = prices[i] - min; 
                //Here we find the maximum comparable profit
        }

        return max;
    }
};