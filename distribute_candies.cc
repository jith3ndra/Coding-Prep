

int distributeCandies(vector<int>& candies) {
        int types=0;
        unordered_map<int,int> map1;
        for(int i=0;i<candies.size();i++){
            if(map1.count(candies[i])){
                map1[candies[i]]++;
            }else{
                map1[candies[i]]=1;
                types++;
            }
        }
        
        return min((int)candies.size()/2,types);
    }
