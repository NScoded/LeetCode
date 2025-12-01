class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=INT_MAX;
        int sell=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<buy) buy=prices[i];
            sell=max(sell,prices[i]-buy);
        }
        return sell;
        
    }
};