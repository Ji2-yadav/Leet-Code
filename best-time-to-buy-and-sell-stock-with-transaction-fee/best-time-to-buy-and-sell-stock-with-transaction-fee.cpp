class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
           int cash = 0, hold = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            int prev_cash = cash;
            cash = max(prev_cash, hold + prices[i] - fee);
            hold = max(hold, prev_cash - prices[i]);
        }
        return cash;
    }
};