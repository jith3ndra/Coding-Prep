

int maxProfit(int k, vector<int>& prices) {
        if(prices.size()==0)return 0;
        if(prices.size()/2<k){
            int res=0;
            for(int i=1;i<prices.size();i++){
                res+= max(0,prices[i]-prices[i-1]);
            }
            return res;
        }else{
            vector<int> buy(k+1,0);
            vector<int> sell(k+1,INT_MIN);
            buy[0]=0;
            for(int i=0;i<prices.size();i++){
                for(int j=k;j>=1;j--){
                    buy[j] = max(buy[j],sell[j]+prices[i]);
                    sell[j] = max(sell[j],buy[j-1]-prices[i]);
                }
                sell[0] = max(sell[0],-prices[i]);
            }
            return buy.back();
        }
    }
