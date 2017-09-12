

int maxProfit(vector<int>& prices) {
        int sell2=INT_MIN,sell1=INT_MIN,rel1 = 0,rel2=0;
        for(int i=0;i<prices.size();i++){
            rel2 = max(rel2,sell2+prices[i]);
            sell2 = max(sell2,rel1-prices[i]);
            rel1 = max(rel1,sell1+prices[i]);
            sell1 = max(sell1,-prices[i]);
        }
        return rel2;
    }
