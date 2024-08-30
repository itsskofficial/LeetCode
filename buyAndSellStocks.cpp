class Solution 
{
    public:
        int maxProfit(vector<int>& prices) 
        {
            int maxProfit, minPrice;
            maxProfit = 0;
            minPrice = prices[0];

            for (int i = 1; i < prices.size(); i++)
            {
                int currentProfit = prices[i] - minPrice;
                maxProfit = max(currentProfit, maxProfit);
                minPrice = min(prices[i], minPrice);
            }

            return maxProfit;
        }
};