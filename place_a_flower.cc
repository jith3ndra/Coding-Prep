


 bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0) return true;
        for(int i=0;i<flowerbed.size();i++){
            if(!i && flowerbed[0]==0 && flowerbed[1]==0){
                n--;
                flowerbed[i]=1;
            }else if(i==flowerbed.size()-1 && !flowerbed[i] && !flowerbed[i-1]){
                n--;
                flowerbed[i]=1;
            }
            else if (flowerbed[i]==0 && !flowerbed[i-1] && !flowerbed[i+1]){
                n--;
                flowerbed[i]=1;
            }
            if(n==0) return true;
        }
        return false;
    }
