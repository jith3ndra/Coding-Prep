int maxProfit(vector<int>& prices) {
        int buy=0,sell=INT_MIN;
        for(int i=0;i<prices.size();i++){
            buy = max(buy,sell+prices[i]);
            sell = max(sell,-prices[i]);
        }
        return buy;
    }
