class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min_buy_price = prices[0];
        int max_profit = 0;

        for(int i=1; i < n; i++){
            int profit_at_sell = prices[i] - min_buy_price; 
            max_profit = max(max_profit, profit_at_sell);
            min_buy_price = min(min_buy_price, prices[i]);
        }
        return max_profit; 
    }
};