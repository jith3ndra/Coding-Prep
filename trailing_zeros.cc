
int trailingZeroes(int n) {
        int res=0;long long val = 5;
        while(n>=val){
            res+= n/val;
            val= val* 5;
        }
        return res;
    }
