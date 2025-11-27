class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell=0;
        int buy=INT_MAX;
        for(int price:prices){
            buy=min(buy,price);
            sell=max(sell,price-buy);
        }
        return sell;
        
    }
};