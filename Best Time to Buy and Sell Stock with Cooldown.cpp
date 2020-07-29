class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int buy(INT_MIN), sell(0), prev_sell(0), prev_buy(0);       
        for(int price: prices)
        {
            prev_buy = buy; 
            buy = max(buy, prev_sell-price);
            prev_sell = sell;
            sell = max(sell, prev_buy+price);
        }
        return sell;
    }
};
