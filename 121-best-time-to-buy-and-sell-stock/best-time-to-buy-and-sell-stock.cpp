class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buystock = prices[0];
        for(int i =1;i<prices.size();i++){
            if(buystock < prices[i]){
                profit = max(profit,prices[i] - buystock);
            }
            buystock=min(buystock,prices[i]);
        }
        return profit;
    }
};