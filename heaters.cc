
int findRadius(vector<int>& houses, vector<int>& heaters) {
        if(!houses.size() || !heaters.size()) return 0;
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int res = 0;int j=0,left=heaters[0],right=heaters[0];
        for(int i=0;i<houses.size();i++){
            while(j<heaters.size()){
                if(heaters[j]<=houses[i]){
                    left = heaters[j];
                    j++;
                }else{
                    break;
                }
            }
            if(j<heaters.size())
                right = heaters[j];
            else
                right = left;
            
            res = max(res,min(abs(left-houses[i]),abs(right-houses[i])));
        }
        return res;
    }
