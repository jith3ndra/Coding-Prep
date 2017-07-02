
    int gcd(int y, int x){
         while(x != 0 ){
        int temp = x;
        x = y%x;
        y = temp;
         }
        return y; 
    }
    bool canMeasureWater(int x, int y, int z) {
        if(!z) return true;
        if(!x || !y) return false;
        if(x+y<z) return false;
        if( x+y==z || x==z || y==z || x-y==z){
            return true;
        }else{
            return (z%gcd(x,y)==0);
        }
    }
